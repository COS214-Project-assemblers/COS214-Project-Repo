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

std::map<std::string, std::vector<std::map<std::string, std::string>>> JSONGameConfiguration::getCustomerTypes()
{
    std::map<std::string, std::vector<std::map<std::string, std::string>>> customerTypes;
    
    try 
    {
        for (auto& [category, customers] : loadedConfig["customers"].items()) 
        {
            customerTypes[category] = customers.get<std::vector<std::map<std::string, std::string>>>();
        }
    } 
    catch (const nlohmann::json::out_of_range& e) 
    {
        throw std::out_of_range("Invalid JSON configuration, could not load customer types");
    }
    
    return customerTypes;
}