#include "LogDecorator.h"

void LogDecorator::setBaseLogger(Logger* logger) {
    if (logger == nullptr) {
        throw std::invalid_argument("Logger cant be null");
    }

    this->logger = logger;
}

LogDecorator::~LogDecorator() {
    delete logger;
}