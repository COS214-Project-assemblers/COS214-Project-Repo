/**
 * @file CoutAndLog.h
 * @brief Decorator for logging to both console and file
 * @author Gerard Jordaan
 */

#ifndef COUT_LOG
#define COUT_LOG

#include "LogDecorator.h"

/**
 * @class CoutAndLog
 * @brief Decorator that logs messages to both console and underlying logger
 * @details Implements the Decorator pattern to extend logging functionality
 * by outputting messages to std::cout before delegating to the base logger.
 * 
 * @see LogDecorator
 * @see Logger
 */
class CoutAndLog : public LogDecorator {
    public:
        /**
         * @brief Logs message to console and then to base logger
         * @param message The message to log
         * @details Outputs message to std::cout with endl before delegating
         * to the underlying logger implementation
         */
        virtual void newLog(std::string message) override;
    
};
#endif