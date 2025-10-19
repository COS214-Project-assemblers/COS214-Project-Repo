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

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

/**
 * @class APIController
 * @warning see I might have might booboo with parent class being called ApiController
 * @brief Sample Api Controller.
 */
class APIController : public oatpp::web::server::api::ApiController {
public:
  /**
   * @brief Constructor with object mapper.
   * @param apiContentMappers - mappers used to serialize/deserialize DTOs.
   */
  APIController(OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers))
    : oatpp::web::server::api::ApiController(apiContentMappers)
  {}
public:
  
  ENDPOINT("GET", "/", root) {
    auto dto = APIDto::createShared();
    dto->statusCode = 200;
    dto->message = "Hello World!";
    return createDtoResponse(Status::CODE_200, dto);
  }
  
  // Further Endpoints
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif // API_CONTROLLERH