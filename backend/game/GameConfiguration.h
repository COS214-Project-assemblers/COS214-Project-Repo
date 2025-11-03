/**
 * @file GameConfiguration.h
 * @brief Interface for obtaining game configuration
 * @author Gerard Jordaan
 * @note Not using namespace std since library used to load JSON uses a different namespace
 */

#ifndef GAMECONFIG
#define GAMECONFIG

#include <vector>
#include <string>
#include <stdexcept>
#include <map>

/**
 * @struct PlantStruct
 * @brief Structure holding plant variety information
 */
struct PlantStruct {
    std::string category;    ///< Plant category name
    std::string variety;     ///< Specific plant variety
    int costPrice;           ///< Purchase cost of the plant
    int salePrice;           ///< Selling price of the plant
};
/**
 * @class GameConfiguration
 * @brief Interface for game configuration providers
 * @details Strategy participant in the Strategy design pattern used to model
 * accessing game configuration. ConcreteStrategies can load configuration from
 * various sources (JSON file, web service, etc.) while maintaining the same interface.
 */
class GameConfiguraton {
    public:
        /**
         * @returns std::map that maps the plant category to a list of its variants
         *  i.e. ["succulent", ["cactus", "other-succulent"]]
         */
        virtual std::vector<PlantStruct*> getPlantVarieties() = 0;

        /**
         * @brief Extracts customer types and their data from loadedConfig
         * @return Map of customer types to their data
         * @throws std::out_of_range
         */
        virtual std::map<std::string, std::map<std::string, std::vector<std::string>>> getCustomerTypes() = 0;

        /**
         * @brief Virtual destructor for proper polymorphic cleanup
         */
        virtual ~GameConfiguraton() {}
};

#endif