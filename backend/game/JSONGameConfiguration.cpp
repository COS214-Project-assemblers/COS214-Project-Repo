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

std::vector<PlantStruct*> JSONGameConfiguration::getPlantVarieties()
{
    std::vector<PlantStruct*> returnStructVec;
    try {
        for (auto& [categoryName, categoryValue] : loadedConfig["plantCategories"].items()) {
            for (auto& [varietyName, varietyValue] : categoryValue.items()) {
                PlantStruct* newStruct = new PlantStruct;

                newStruct->category = categoryName;
                newStruct->variety = varietyName;
                newStruct->costPrice = varietyValue["costPrice"];
                newStruct->salePrice = varietyValue["salePrice"];

                returnStructVec.push_back(newStruct);
            }
        }
    } catch (const nlohmann::json::out_of_range& e) {
         throw std::out_of_range("Invalid JSON configuration, could not load plant variants");
    }
    
    return returnStructVec;
}