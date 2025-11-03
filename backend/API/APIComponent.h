/**
 * @file APIComponent.h
 * @brief Refer to docs https://oatpp.io/docs/start/step-by-step/#application-components-configuration
 */
#ifndef APICOMP
#define APICOMP

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/mime/ContentMappers.hpp"

#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/json/ObjectMapper.hpp"

#include "oatpp/macro/component.hpp"

/**
 * @class APIComponent
 * @brief Holds API components for dependency injection
 * @details Registers components in oatpp::base::Environment. Configures server, 
 * router, connection handlers and JSON mappers. All components created via Macros. 
 * For lower level implementation details visit the docs.
 * 
 * Oat++ flow: ConnectionProvider (TCP) -> Server -> HttpConnectionHandler -> HttpRouter
 */
class APIComponent {
    public:
        /**
         * @brief Macro (details hidden) to create ServerConnectionProvider component
         *  listens for TCP packets on port 8000
         */
        OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([] {
            return oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000, oatpp::network::Address::IP_4});
        }());
        /**
         * @brief Macro to Create HttpRouter component
         * @note Oat++ flow: ConnectionProvider (TCP) -> Server -> HttpConnectionHandler -> HttpRouter
         * @note shared -> thread for each connection
         */
        OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
            return oatpp::web::server::HttpRouter::createShared();
        }());
        /**
         * @brief ConnectionHandler uses router to route requests
         */
        OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)([] {
            OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
            return oatpp::web::server::HttpConnectionHandler::createShared(router);
        }());
        /**
         * @brief Serialize/Desserialize (https://en.wikipedia.org/wiki/Serialization) DTOs (https://en.wikipedia.org/wiki/Data_transfer_object)
         *  with JSON in controller API
         */
        OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers)([] {

            auto json = std::make_shared<oatpp::json::ObjectMapper>();
            json->serializerConfig().json.useBeautifier = true;

            auto mappers = std::make_shared<oatpp::web::mime::ContentMappers>();
            mappers->putMapper(json);

            return mappers;

        }());
    };

#endif