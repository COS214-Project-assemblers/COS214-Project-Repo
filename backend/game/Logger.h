/**
 * @file Logger.h
 * @brief Header for Strategy Logger
 * @author Gerard Jordaan
 */

#ifndef LOGGER
#define LOGGER

#include <string>
#include <iostream>
#include <stdexcept>

/**
 * @class Logger
 * @brief Interface for concrete Log strategies to implement
 */
class Logger {
    public:
        /**
         * @brief Pure virtual function that acts as the algorithm the concrete strategies are to implement
         * @param[in] message Content of log message
         */
        virtual void newLog(std::string message) = 0;
        virtual ~Logger() {};
};

#endif // LOGGER