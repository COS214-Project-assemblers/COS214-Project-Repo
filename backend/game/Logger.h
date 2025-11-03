/**
 * @file Logger.h
 * @brief Header for Strategy Logger interface
 * @author Gerard Jordaan
 */

#ifndef LOGGER
#define LOGGER

#include <string>
#include <iostream>
#include <stdexcept>

/**
 * @class Logger
 * @brief Interface for concrete logging strategies
 * @details Defines the common interface for all logging implementations
 * following the Strategy pattern. Concrete strategies implement specific
 * logging mechanisms (file, console, etc.).
 * 
 * @see BasicLogger
 * @see LogDecorator
 */
class Logger {
    public:
        /**
         * @brief Pure virtual function that acts as the algorithm the concrete strategies are to implement
         * @param[in] message Content of log message
         */
        virtual void newLog(std::string message) = 0;
        
        /**
         * @brief Virtual destructor for proper polymorphic cleanup
         */
        virtual ~Logger() {};
};

#endif