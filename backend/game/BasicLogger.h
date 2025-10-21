/**
 * @file Logger.h
 * @brief Header file for Logger class
 * @author Gerard Jordaan
 */

#ifndef BASICLOGGER
#define BASICLOGGER

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>

#include "Logger.h"

using namespace std;

class BasicLogger : public Logger {
    private:
        /**
         * @brief Filename of Log File, set in Logger constructor
         */
        string fileName;
        ofstream file;
    public:
        /**
         * @brief Loads and sets Log File filename from environment variables
         */
        BasicLogger();
        void newLog(string message) override;
        /**
         * @brief Returns current timestamp
         */
        string timestamp();
        ~BasicLogger();
};

#endif // BASICLOGGER