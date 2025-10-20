/**
 * @file Logger.h
 * @brief Header file for Logger class
 * @author Gerard Jordaan
 */

#ifndef LOGGER
#define LOGGER

#include <string>
#include <iostream>

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
        void newLog(string message);
};

#endif // LOGGER