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

struct PlantStruct {
    std::string category;
    std::string variety;
    int costPrice;
    int salePrice;
};

/**
 * @class GameConfiguration
 * @brief Interface that provides unified interface to clients wanting to read
 *  game configurations. GameConfig is the Strategy participant in the Strategy design
 *  pattern used to model accessing the game configuration. The ConcreteStrategies
 *  that inherit from this interface can load the configuration in any necessary mode,
 *  thus ensuring extensibility (i.e. JSON file config, web config, interface remains the same)
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

        virtual ~GameConfiguraton() {}
};

#endif // GAMECONFIG