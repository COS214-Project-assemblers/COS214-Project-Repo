/**
 * @file API.h
 * @brief Bootstrapper for public facing API
 * @author Gerard Jordaan
 */

#ifndef API_H
#define API_H

#include "APIController.h"
#include "APIComponent.h"

#include "oatpp/network/Server.hpp"
#include <iostream>

/**
 * @class API
 * @brief Bootstraps (starts) public facing API
 */
class API {
    public:
        void run();
        void bootstrap();
};

#endif // API_H