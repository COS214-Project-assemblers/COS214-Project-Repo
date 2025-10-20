/**
 * @file Logger.h
 * @brief Header file for Logger class
 * @author Gerard Jordaan
 */

#ifndef LOGGER
#define LOGGER

#include <string>
using namespace std;

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
};

#endif // LOGGER