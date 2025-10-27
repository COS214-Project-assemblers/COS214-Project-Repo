/**
 * @file LogDecorator.h
 * @author Gerard Jordaan
 */

#ifndef LOG_DEC
#define LOG_DEC

#include "Logger.h"

/**
 * @class LogDecorator
 * @brief Allows user to add extended functionality to the log ConcreteStrategies, i.e.
 *  can add cout before log along with some colours/custom formatting
 */
class LogDecorator : public Logger {
    protected:
        Logger* logger = nullptr;
    public:
        /**
         * @brief placeholder for ConcreteDecorators to inherit from
         */
        virtual void newLog(std::string message) override {
            std::cout << "Extending logger functionality for log message " << message << std::endl;
        }
        /**
         * @throws invalid_argument when logger == nullptr
         */
        void setBaseLogger(Logger* logger);

        virtual ~LogDecorator();
};

#endif // LOG_DEC