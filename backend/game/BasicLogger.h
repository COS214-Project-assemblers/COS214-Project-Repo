/**
 * @file BasicLogger.h
 * @brief Header file for BasicLogger ConcreteStrategy
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

/**
 * @class BasicLogger
 * @brief Implements Logger interface. Reads LOG_FILE (log file path) environment variable, opens
 *  and appends log message and timestamp to the file 
 */
class BasicLogger : public Logger {
    private:
        /**
         * @brief Filename of Log File, read from environment, LOG_FILE
         */
        string fileName;
        /**
         * @brief object representing file to append logs to
         */
        ofstream file;
    public:
        /**
         * @brief Loads and sets filename from environment variable LOG_FILE
         *  Opens the file, loads into mem
         */
        BasicLogger();
        /**
         * @brief Appends to the log file in the following format:
         *  [timestamp] <message>
         */
        void newLog(string message) override;
        /**
         * @brief Returns current timestamp <weekday month day hh:ss:mm year>
         * @returns Tue Oct 21 16:37:50 2025
         */
        string timestamp();
        /**
         * @brief Closes file
         */
        ~BasicLogger();
};

#endif // BASICLOGGER