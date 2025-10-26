/**
 * @file EnvironmentInitializer.h
 * @author Gerard Jordaan
 */

#ifndef ENVINIT
#define ENVINIT

#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

/**
 * @class EnvironmentInitializer
 * @brief Inits environment vars by reading them from .env file
 * 
 * For configurations such as log file paths/game configuration file paths,
 * environment variables can be really useful, particurly useful in the case
 * of sensitive data like DB usernames and passwords. This class aims to 
 * centralize/abstract that task for our system
 */
class EnvironmenntInitializer {
    private:
        string envFilePath;
    public:
        /**
         * @brief Setter for envFilePath member variable
         */
        EnvironmenntInitializer(string envFilePath);
        /**
         * @brief Reads file, sets env vars
         * @throws std::ios_base::failure if the file could not be opened
         * @throws std::invalid_argument if the file could be opened, but the env vars
         *  could not be initialized
         */
        void initEnv();
};

#endif // ENVINIT