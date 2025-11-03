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
 * @brief Implements Logger interface for file-based logging
 * @details Reads LOG_FILE environment variable for log file path, opens
 * and appends log messages with timestamps to the file. Follows the
 * Strategy pattern as a ConcreteStrategy for logging.
 * 
 * @see Logger
 */
class BasicLogger : public Logger {
    private:
        /**
         * @brief Filename of Log File, read from environment variable LOG_FILE
         */
        string fileName;

        /**
         * @brief Object representing file to append logs to
         */
        ofstream file;

    public:

        /**
         * @brief Constructor - loads and sets filename from environment variable LOG_FILE
         * @details Opens the file for appending log messages
         */
        BasicLogger();

        /**
         * @brief Appends a log message to the log file with timestamp
         * @param message The log message to append
         * @details Format: [timestamp] message
         */
        void newLog(string message) override;

        /**
         * @brief Generates current timestamp string
         * @return Timestamp in format: "Tue Oct 21 16:37:50 2025"
         */
        string timestamp();

        /**
         * @brief Destructor - closes the log file
         */
        ~BasicLogger();
};

#endif