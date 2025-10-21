#include "Logger.h"

Logger::Logger() {
    // Nothing yet
}

void Logger::newLog(string message) {
    cout << "[" + timestamp() + "] " + message << endl;
}

string Logger::timestamp() {
    std::time_t timestamp = std::time(nullptr);

    // Convert to a human-readable string (local time)
    char* time_str = std::ctime(&timestamp);
    time_str[strlen(time_str) - 1] = '\0';

    return time_str; 
}