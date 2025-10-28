#include "CoutAndLog.h"

void CoutAndLog::newLog(std::string message) {
    std::cout << message << std::endl;
    if (logger != nullptr) {
        logger->newLog(message);
    }
}