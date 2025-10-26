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
  
  // Further Endpoints

  ENDPOINT("POST", "/buy-plants", buyPlants,
         QUERY(String, plant, "plant"),
         QUERY(Int32, num, "num")) {
    /**
     * Response structure
     * 
     * {
     *  message: <operation-status>,
     *  statusCode: <HTTP status code, 200/400/500>
     * }
     */
    auto dto = APIDto::createShared();

    // Input validation
    if (!plant || plant->empty())
    {
      dto->statusCode = 400;
      dto->message = "Plant variety parameter is required";
      
      return createDtoResponse(Status::CODE_400, dto);
    }

    if (!num || num->getValue() <= 0) 
    {
      dto->statusCode = 400;
      dto->message = "Number of plants must be a positive integer";

      return createDtoResponse(Status::CODE_400, dto);
    }

    try 
    {
      apiToControl.game->buyPlants(plant->std_str(), num->getValue());
      
      dto->statusCode = 200;
      dto->message = "Successfully bought " + std::to_string(*num) + " " + *plant + " plants using cloning";

      return createDtoResponse(Status::CODE_200, dto);
    } 
    catch (const std::exception &e) 
    {
      dto->statusCode = 500;
      dto->message = "Failed to buy plants: " + std::string(e.what());

      return createDtoResponse(Status::CODE_500, dto);
    }
  }
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif // API_CONTROLLERH