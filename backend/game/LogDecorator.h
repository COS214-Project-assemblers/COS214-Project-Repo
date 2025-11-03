/**
 * @file LogDecorator.h
 * @brief Base decorator class for extending logger functionality
 * @author Gerard Jordaan
 */

#ifndef LOG_DEC
#define LOG_DEC

#include "Logger.h"

/**
 * @class LogDecorator
 * @brief Base decorator for extending logger functionality
 * @details Implements the Decorator pattern to allow adding extended
 * functionality to logger ConcreteStrategies, such as console output,
 * custom formatting, or colors.
 * 
 * @see Logger
 * @see CoutAndLog
 */
class LogDecorator : public Logger {
    protected:
        /**
         * @brief Wrapped logger instance being decorated
         */
        Logger* logger = nullptr;

    public:

        /**
         * @brief Default log implementation for decorators
         * @param message The log message to process
         * @details Can be overridden by concrete decorators
         */
        virtual void newLog(std::string message) override {
            std::cout << "Extending logger functionality for log message " << message << std::endl;
        }

        /**
         * @brief Sets the base logger to be decorated
         * @param logger Pointer to Logger instance to wrap
         * @throws std::invalid_argument if logger is nullptr
         */
        void setBaseLogger(Logger* logger);

        /**
         * @brief Virtual destructor for proper polymorphic cleanup
         */
        virtual ~LogDecorator();
};

#endif