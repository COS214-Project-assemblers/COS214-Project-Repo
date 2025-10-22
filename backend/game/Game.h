/**
 * @file Game.h
 * @brief Header file for Game class
 * @author Gerard Jordaan
 */
#ifndef GAME_HDR
#define GAME_HDR

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

// For now, and to be safe, I am forward declaring classes instead of including
// their header files to avoid circular dependencies, i.e. the Greenhouse class 
// can include Game.h in its header file and then we are fu..screwed (just checking
// if you are actually reading comments)
class Greenhouse;
class PlantCreator;

/**
 * @class Game
 * @brief The Game class represents the internal API of the system.
 *  It is modelled in terms of the Facade design pattern.
 */
class Game {
    private:
        /**
         * @brief attribute that maintains reference to the game's greenhouse object
         */
        Greenhouse* greenhouse;
        /**
         * @brief maintains reference to plant creators for the game
         */
        vector<PlantCreator*> factories;
    public:
        /**
         * @brief Game initialization tasks that are not creating/loading game.
         *  Wil problably init DB connection etc here
         */
        Game();
        /**
         * @brief Setter for greenhouse attribute
         * @param[in] greenhouse Greenhouse reference
         */
        void setGreenhouse(Greenhouse* greenhouse);
        /**
         * @brief Getter for testing purposes
         */
        Greenhouse* getGreenhouse();
        /**
         * @brief Setter for factories
         * @param[in] factories Vector of PlantCreator object references, these are the "factories"
         */
        void setFactories(vector<PlantCreator*> factories);
        /**
         * @brief Getter for testing purposes
         */
        vector<PlantCreator*> getFactories();
        /**
         * @brief Operations associated with creating a new game, i.e. creating greenhouse and factories
         */
        void createNewGame();
        /**
         * @brief The following is taken from the notion board, @Megan thought of this function
         *  This is used by the user to be able to buy plants to add to the Greenhouse.
         *  Calls the Plant method makePlant() to create the plants.
         */
        void buyPlants(string plant, int num);
        /**
         * @brief loads greenhouse and factories from DB
         */
        void loadExistingGame();
        /**
         * Saves state of greenhouse and factories in DB
         */
        void saveGame();
        /**
         * @brief Frees greenhouse, plant creators memory. Closes DB connection.
         */
        ~Game();
};

#endif // GAME_HDR