/**
 * @file APIController.h
 * @brief Define endpoints
 * @note Inspiration from https://github.com/oatpp/oatpp-starter/blob/master/src/controller/MyController.hpp
 * @author Gerard Jordaan
 */
#ifndef API_CONTROLLERH
#define API_CONTROLLERH

#include "APIDto.h"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/macro/codegen.hpp"
#include "oatpp/macro/component.hpp"
#include "Game.h"
#include "PlayerMenu.h"
#include "NewGameOption.h"
#include "ContinueGameOption.h"
#include "BasicLogger.h"
#include "API.h"
#include "ExitGameOption.h"
#include <cstdlib>
#include <stdexcept>
#include <memory>
#include <iostream>

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

/**
 * @class APIController
 * @warning see I might have might booboo with parent class being called ApiController
 * @brief Sample Api Controller.
 */
class APIController : public oatpp::web::server::api::ApiController {
  private:
  /**
   * @brief Via this member variable, access to private members of the API class (such as "game" member var)
   *  is obtained
   */
    API& apiToControl;
public:
  /**
   * @brief Constructor with object mapper.
   * @param apiContentMappers - mappers used to serialize/deserialize DTOs.
   */
  APIController(std::shared_ptr<oatpp::web::mime::ContentMappers>& apiContentMappers, API& inApi)
    : oatpp::web::server::api::ApiController(apiContentMappers), apiToControl(inApi)
  {}

  static std::shared_ptr<APIController> createShared(API& inApi) {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers);
    return std::make_shared<APIController>(apiContentMappers, inApi);
  }
public:
  
  ENDPOINT("GET", "/", root) {
    auto dto = APIDto::createShared();
    dto->statusCode = 200;
    dto->message = "Hello World!";
    return createDtoResponse(Status::CODE_200, dto);
  }

  // ENDPOINT("GET", "/get-balance", root) {
  //   auto dto = APIDto::createShared();
  //   dto->statusCode = 200;
  //   dto->message = "Hello World!";
  //   return createDtoResponse(Status::CODE_200, dto);
  // }
  
  /**
   * @brief Executes NewGameOption Command
   */
  ENDPOINT("GET", "/new-game", newGameEndp) {
    /**
     * Response structure
     * 
     * {
     *  message: <game-status>,
     *  statusCode: <HTTP status code, 200/500>
     * }
     */
    
    if (apiToControl.game == nullptr)
    {
      char* gameConfigPath = getenv("GAME_CONFIG_PATH");
      if (gameConfigPath == nullptr) {
          std::cout << "GAME_CONFIG_PATH environment variable not set, exiting..." << std::endl;
          exit(EXIT_FAILURE);
      }
      apiToControl.game = new Game(gameConfigPath);
    }

    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGame = new NewGameOption(apiToControl.game, logger);
    playerMenu->setMenuOption(newGame);

    auto dto = APIDto::createShared();

    try {
      playerMenu->executeOption();
      // Deleting playerMenu also frees newGame
      delete playerMenu;
      delete logger;
      dto->statusCode = 200;
      dto->message = "Game Created";
      return createDtoResponse(Status::CODE_200, dto);
    } catch (const std::exception &e) { // Catches any exception thrown, adds exception message to response
      delete playerMenu;
      delete logger;
      dto->statusCode = 500;
      dto->message = "Failed to create Game: " + *e.what();
      return createDtoResponse(Status::CODE_500, dto);
    }   
  }
  
  ENDPOINT("GET", "/exit-game", exitGameEndp) {
    /**
     * Response structure
     * 
     * {
     *  message: <game-status>,
     *  statusCode: <HTTP status code, 200/500>
     * }
     */
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    ExitGameOption* exitGame = new ExitGameOption(apiToControl.game, logger);
    playerMenu->setMenuOption(exitGame);

    auto dto = APIDto::createShared();

    try {
      playerMenu->executeOption();
      // Deleting playerMenu also frees newGame
      delete playerMenu;
      delete logger;
      dto->statusCode = 200;
      dto->message = "Game Exited";
      return createDtoResponse(Status::CODE_200, dto);
    } catch (const std::exception &e) { // Catches any exception thrown, adds exception message to response
      delete playerMenu;
      delete logger;
      dto->statusCode = 500;
      dto->message = "Failed to exit Game: " + *e.what();
      return createDtoResponse(Status::CODE_500, dto);
    }   
  }
  // Further Endpoints

  ENDPOINT("POST", "/buy-plants", buyPlants, BODY_DTO(oatpp::Object<BuyPlantDTO>, body)) 
  {
    /**
     * Response structure
     * 
     * {
     *  message: <operation-status>,
     *  statusCode: <HTTP status code, 200/400/500>
     * }
     */
    auto dto = APIDto::createShared();

    // Input validation using the request body DTO
    if (!body) {
      dto->statusCode = 400;
      dto->message = "Request body is required";
      return createDtoResponse(Status::CODE_400, dto);
    }

    if (!body->plant || body->plant->empty()) 
    {
      dto->statusCode = 400;
      dto->message = "Plant variety parameter is required in request body";
      return createDtoResponse(Status::CODE_400, dto);
    }

    if (!body->numToBuy || *body->numToBuy <= 0) 
    {
      dto->statusCode = 400;
      dto->message = "Number of plants must be a positive integer in request body";
      return createDtoResponse(Status::CODE_400, dto);
    }

    try 
    {
      // Extract values from the request body DTO
      std::string plantStr = body->plant->c_str();
      int numValue = *body->numToBuy;
      
      apiToControl.game->buyPlants(plantStr, numValue);
      
      dto->statusCode = 200;
      dto->message = "Successfully bought " + std::to_string(numValue) + " " + plantStr + " plants using cloning";
      return createDtoResponse(Status::CODE_200, dto);
    } 
    catch (const std::exception &e) 
    {
      dto->statusCode = 500;
      dto->message = "Failed to buy plants: " + std::string(e.what());
      return createDtoResponse(Status::CODE_500, dto);
    }
  }

  ENDPOINT("POST", "/add-customers", addCustomers, BODY_DTO(oatpp::Object<AddCustomerDTO>, body)) 
  { 
    // Expected request structure:
    // {
    //   "customerType": "ignorant",
    //   "numToAdd": 5
    // }
    
    auto dto = APIDto::createShared();

    if (!body) 
    {
      dto->statusCode = 400;
      dto->message = "Request body is required";
      
      return createDtoResponse(Status::CODE_400, dto);
    }

    if (!body->customerType || body->customerType->empty()) 
    {
      dto->statusCode = 400;
      dto->message = "Customer type parameter is required in request body";

      return createDtoResponse(Status::CODE_400, dto);
    }

    if (!body->numToAdd || *body->numToAdd <= 0) 
    {
      dto->statusCode = 400;
      dto->message = "Number of customers must be a positive integer in request body";

      return createDtoResponse(Status::CODE_400, dto);
    }

    try 
    {
      std::string customerTypeStr = body->customerType->c_str();
      int numValue = *body->numToAdd;
  
      apiToControl.game->createCustomers(customerTypeStr, numValue);
      
      dto->statusCode = 200;
      dto->message = "Successfully added " + std::to_string(numValue) + " " + customerTypeStr + " customers";

      return createDtoResponse(Status::CODE_200, dto);
    } 
    catch (const std::exception &e) 
    {
      dto->statusCode = 500;
      dto->message = "Failed to add customers: " + std::string(e.what());

      return createDtoResponse(Status::CODE_500, dto);
    }
  }

  ENDPOINT("GET", "/customers", getCustomers) 
  {
    auto dto = CustomerResponseDTO::createShared();

    try 
    {
      std::string customersJson = apiToControl.game->getCustomersAsJson();
      
      dto->statusCode = 200;
      dto->message = "Successfully retrieved customers";
      dto->customersJson = String(customersJson.c_str());
      
      return createDtoResponse(Status::CODE_200, dto);
    } 
    catch (const std::exception &e) 
    {
      dto->statusCode = 500;
      dto->message = "Failed to get customers: " + std::string(e.what());
      
      return createDtoResponse(Status::CODE_500, dto);
    }
  }

  ENDPOINT("GET", "/balance", getBalance)
  {
    auto dto = BalanceResponseDTO::createShared();

    try 
    {
      double currentBalance = apiToControl.game->getGameBalance();
      
      dto->statusCode = 200;
      dto->message = "Successfully retrieved balance";
      dto->balance = currentBalance;
      
      return createDtoResponse(Status::CODE_200, dto);
    } 
    catch (const std::exception &e) 
    {
      dto->statusCode = 500;
      dto->message = "Failed to get balance: " + std::string(e.what());
      dto->balance = 0.0; // Default value on error
      
      return createDtoResponse(Status::CODE_500, dto);
    }
  }

  ENDPOINT("GET", "/greenhouse/plants", getGreenhousePlants)
  {
    auto dto = APIDto::createShared();

    try 
    {
      std::string plantsJson = apiToControl.game->getGreenhousePlantsAsJson();
      
      dto->statusCode = 200;
      dto->message = "Successfully retrieved greenhouse plants";
      dto->data = String(plantsJson.c_str());
      
      return createDtoResponse(Status::CODE_200, dto);
    } 
    catch (const std::exception &e) 
    {
      dto->statusCode = 500;
      dto->message = "Failed to get greenhouse plants: " + std::string(e.what());
      dto->data = {};
      
      return createDtoResponse(Status::CODE_500, dto);
    }
  }
};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif // API_CONTROLLERH