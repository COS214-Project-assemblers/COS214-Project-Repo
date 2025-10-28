#include "BasicLogger.h"

BasicLogger::BasicLogger() {
    // Nothing yet
    char* logFile = getenv("LOG_FILE");

    if (logFile == nullptr) {
        logFile = "log.txt";
    }
    
    cout << "Opening log file " + static_cast<string>(logFile) << endl;;
    file.open(logFile, ios::app);


    if (!file) {
        cout << "File " + static_cast<string>(logFile) + " could not be written to." << endl; 
    }
}

void BasicLogger::newLog(string message) {
    // Try get new file
    string logEntry = "[" + timestamp() + "] " + message;

    if (file) {
        file << logEntry << endl;
    } 
}

string BasicLogger::timestamp() {
    std::time_t timestamp = std::time(nullptr);

    // Convert to a human-readable string (local time)
    char* time_str = std::ctime(&timestamp);
    time_str[strlen(time_str) - 1] = '\0';

    return time_str; 
}

BasicLogger::~BasicLogger() {
    file.close();
}