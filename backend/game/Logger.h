/**
 * @file Logger.h
 * @brief Header file for Logger class
 * @author Gerard Jordaan
 */

#ifndef LOGGER
#define LOGGER

#include <string>

class Logger {
    private:
        /**
         * @brief Filename of Log File, set in Logger constructor
         */
        string fileName;
    public:
        /**
         * @brief Loads and sets Log File filename from environment variables
         */
        Logger();
        void newLog(std::string message);
};

#endif // LOGGER