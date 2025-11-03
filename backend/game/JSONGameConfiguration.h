/**
 * @file JSONGameConfiguration.h
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
 * @brief Implements GameConfiguration interface. ConcreteStrategy participant. Loads
 *  data from .json file, implements methods to retrieve configurations
 */
class JSONGameConfiguration : public GameConfiguraton {
    private:
        json loadedConfig;
        /**
         * @brief Method is called in constructor. Seperate load implementation to keep 
         *  constructor clean and make class maintainable.
         * @param[in] configPath Absolute or relative path of .json config file
         * @throws std::ios_base::failure
         */
        void loadConfig(std::string configPath);
    public:
        /**
         * @brief Calls this->loadConfig, error handling logic
         * @throws std::runtime_error 
         */
        JSONGameConfiguration(std::string configPath);

        /**
         * @brief Extracts customer types and their data from loadedConfig
         * @return Map of customer types to their data
         * @throws std::out_of_range
         */
        virtual std::map<std::string, std::map<std::string, std::vector<std::string>>> getCustomerTypes() override;
        virtual std::vector<PlantStruct*> getPlantVarieties() override;
};

#endif // JSONCONF