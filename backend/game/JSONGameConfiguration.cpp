#include "JSONGameConfiguration.h"

void JSONGameConfiguration::loadConfig(std::string configPath)
{
    std::ifstream f;
    f.exceptions(std::ios::failbit | std::ios::badbit);
    f.open(configPath);
    
    f >> loadedConfig;

    f.close();
}

JSONGameConfiguration::JSONGameConfiguration(std::string configPath)
{
    try {
        loadConfig(configPath);
    } catch (const std::ios_base::failure& e) {
        throw std::runtime_error("Failed to load " + configPath);
    }
}

std::map<std::string, std::vector<std::string>> JSONGameConfiguration::getPlantVarieties()
{
    std::map<std::string, std::vector<std::string>> plantVarieties;
    try {
        for (auto& [category, variants] : loadedConfig["plantVarieties"].items()) {
            plantVarieties[category] = variants.get<std::vector<std::string>>();
        }
    } catch (const nlohmann::json::out_of_range& e) {
         throw std::out_of_range("Invalid JSON configuration, could not load plant variants");
    }
    
    return plantVarieties;
}

std::map<std::string, std::map<std::string, std::vector<std::string>>> JSONGameConfiguration::getCustomerTypes()
{
    std::map<std::string, std::map<std::string, std::vector<std::string>>> customerTypes;

    try
    {
        for (auto& [customerType, categories] : loadedConfig["customers"].items())
        {
            std::map<std::string, std::vector<std::string>> categoryMap;

            for (auto& [categoryName, valueArray] : categories.items())
            {
                categoryMap[categoryName] = valueArray.get<std::vector<std::string>>();
            }

            customerTypes[customerType] = std::move(categoryMap);
        }
    }
    catch (const nlohmann::json::exception& e)
    {
        throw std::runtime_error(std::string("Error loading customer types: ") + e.what());
    }

    return customerTypes;
}