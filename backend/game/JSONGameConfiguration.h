/**
 * @file JSONGameConfiguration.h
 * @brief JSON-based game configuration implementation
 * @author Gerard Jordaan
 */

#ifndef JSONCONF
#define JSONCONF

#include <fstream>
#include <nlohmann/json.hpp>
#include "GameConfiguration.h"
using json = nlohmann::json;

/**
 * @class JSONGameConfiguration
 * @brief Implements GameConfiguration interface for JSON file configuration
 * @details ConcreteStrategy participant that loads game configuration data
 * from JSON files. Implements methods to retrieve plant varieties and customer types.
 * 
 * @see GameConfiguration
 */
class JSONGameConfiguration : public GameConfiguraton {
    private:
        /**
         * @brief JSON object containing loaded configuration
         */
        json loadedConfig;

        /**
         * @brief Loads configuration from JSON file
         * @param configPath Absolute or relative path of .json config file
         * @throws std::ios_base::failure if file cannot be opened or parsed
         */
        void loadConfig(std::string configPath);

    public:

        /**
         * @brief Constructor - loads configuration from specified path
         * @param configPath Path to JSON configuration file
         * @throws std::runtime_error if configuration loading fails
         */
        JSONGameConfiguration(std::string configPath);

        /**
         * @brief Extracts customer types and their data from loaded configuration
         * @return Map of customer types to their dialogue data
         */
        virtual std::map<std::string, std::map<std::string, std::vector<std::string>>> getCustomerTypes() override;

        /**
         * @brief Extracts plant varieties from loaded configuration
         * @return Vector of PlantStruct pointers with plant information
         */
        virtual std::vector<PlantStruct*> getPlantVarieties() override;
};

#endif