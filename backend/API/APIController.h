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
#include "../game/Game.h"
#include "../game/PlayerMenu.h"
#include "../game/NewGameOption.h"
#include "../game/ContinueGameOption.h"

#include <stdexcept>
#include <memory>

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

/**
 * @class APIController
 * @warning see I might have might booboo with parent class being called ApiController
 * @brief Sample Api Controller.
 */
class APIController : public oatpp::web::server::api::ApiController {
  private:
    Game* game;
public:
  /**
   * @brief Constructor with object mapper.
   * @param apiContentMappers - mappers used to serialize/deserialize DTOs.
   */
  APIController(std::shared_ptr<oatpp::web::mime::ContentMappers>& apiContentMappers, Game* game)
    : oatpp::web::server::api::ApiController(apiContentMappers), game(game)
  {}

  static std::shared_ptr<APIController> createShared(Game* game) {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers);
    return std::make_shared<APIController>(apiContentMappers, game);
  }
public:
  
  ENDPOINT("GET", "/", root) {
    auto dto = APIDto::createShared();
    dto->statusCode = 200;
    dto->message = "Hello World!";
    return createDtoResponse(Status::CODE_200, dto);
  }
  
  ENDPOINT("GET", "/new-game", newGame) {
    auto playerMenu = std::make_unique<PlayerMenu>();
    auto newGame = std::make_unique<NewGameOption>(game);
    
    playerMenu->setMenuOption(newGame.get());

    auto dto = APIDto::createShared();

    try {
      playerMenu->executeOption();
      dto->statusCode = 200;
      dto->message = "Game Created";
      return createDtoResponse(Status::CODE_200, dto);
    } catch (const std::exception &e) {
      dto->statusCode = 500;
      dto->message = "Failed to create Game";
      return createDtoResponse(Status::CODE_500, dto);
    }   
  }
  
  // Further Endpoints
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif // API_CONTROLLERH