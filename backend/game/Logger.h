#ifndef LOGGER
#define LOGGER

#include <string>

class Logger {
    public:
        virtual void newLog(std::string message) = 0;
};

#endif // LOGGER