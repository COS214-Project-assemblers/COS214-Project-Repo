/**
 * @file PlantHealth.h
 * @brief Health management system for plant lifecycle and care requirements
 */

#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>
#include <mutex>
#include <chrono>
#include <random>
#include "GreenSock.h"
#include <sstream>
#include <iomanip>

class Plant;

/**
 * @class Health
 * @brief Manages plant health metrics including water, fertilizer, pruning, and maturity
 * 
 * The Health class is responsible for tracking and managing all aspects of a plant's
 * well-being. It provides thread-safe operations for care handling and implements
 * decay mechanics that simulate natural plant lifecycle processes.
 */
class Health {
    friend class Plant ;
    
    protected:
        float originalHeathTotal;    ///< Baseline health total for reference
        float water;                 ///< Water level
        float fertalizer;            ///< Fertilizer level
        float pruning;               ///< Pruning level
        int mature;                  ///< Maturity level
        GreenSock* socket;           ///< WebSocket for real-time health updates

        mutable std::mutex mtx;      ///< Mutex for thread-safe health operations

        mutable std::mt19937 rng;    ///< Random number generator for decay behavior
        mutable std::uniform_int_distribution<int> dist;  ///< Distribution for random decay

    public:

        /**
         * @brief Constructs a Health object with given or default parameters.
         *
         * Initializes health metrics to represent a plant’s starting state. Also seeds
         * a random number generator and uniform distribution used for decay behavior.
         *
         * @param water Initial water level (default 1.0)
         * @param fertalizer Initial fertilizer level (default 1.0)
         * @param pruning Initial pruning level (default 1.0)
         * @param mature Initial maturity level (default 0)
         */
        Health(float water = 1.0 , float fertalizer = 1.0 , float pruning = 1.0 , int mature= 0);

        /**
         * @brief Gets water level as formatted string.
         * @return Water level string representation
         */
        std::string getWater();
        
        /**
         * @brief Gets fertilizer level as formatted string.
         * @return Fertilizer level string representation
         */
        std::string getFertilizer();
        
        /**
         * @brief Gets pruning level as formatted string.
         * @return Pruning level string representation
         */
        std::string getPruning();

        /**
         * @brief Destructor for Health.
         * Currently, no dynamic memory is managed by Health, so this destructor is empty.
         */
        ~Health();

        /**
         * @brief Copy constructor deleted to prevent unintended copying.
         */
        Health(const Health&) = delete;
        
        /**
         * @brief Copy assignment operator deleted.
         */
        Health& operator=(const Health&) = delete;
        
        /**
         * @brief Move constructor enabled for efficient resource transfer.
         */
        Health(Health&&) = default;
        
        /**
         * @brief Move assignment operator enabled.
         */
        Health& operator=(Health&&) = default;

        /**
         * @brief Handles watering by restoring the water attribute to full (1.0).
         *
         * Uses a mutex lock to ensure thread-safe modification. Prints the amount of
         * water required before replenishment.
         */
        void handleWater();

        /**
         * @brief Handles fertilizer replenishment by restoring the fertilizer attribute to full (1.0).
         *
         * Uses a mutex lock to ensure thread-safe modification. Prints the amount of
         * fertilizer required before replenishment.
         */
        void handleFertilizer()     ;


        /**
         * @brief Handles pruning by restoring the pruning attribute to full (1.0)
         * AND INCREASES MATURITY.
         * Uses a mutex lock to ensure thread-safe modification. Prints the amount of
         * pruning required before action.
         */
        void handlePruning()        ;

        /**
         * @brief Creates a clone of the current Health object.
         * Allocates and returns a new Health object with default constructor parameters.
         * @return Pointer to a newly created Health instance.
         */
        std::unique_ptr<Health> clone() const;

        /**
         * @brief Computes the overall health score.
         * The health score is a simple additive measure of the plant’s
         * water, fertilizer, and pruning levels.
         * @return The total health score (float), typically in the range [0, 3].
         */
        float healthScore();

        /**
         * @brief Gets current water level.
         * @return Water level as float
         */
        float Water();

        /**
         * @brief Gets current fertilizer level.
         * @return Fertilizer level as float
         */
        float Fertilizer();

        /**
         * @brief Gets current pruning level.
         * @return Pruning level as float
         */
        float healthPrune();

        /**
         * @brief Retrieves the maturity level of the plant.
         * @return Integer representing how mature the plant is.
         */
        int getMaturity()           ;

        /**
         * @brief Simulates natural health decay over time.
         *
         * Based on the provided decay index, a corresponding health attribute
         * (water, fertilizer, or pruning) is reduced by 0.4, not dropping below 0.0.
         *
         * @param decayIndex Integer in range [0,2], selecting which attribute to decay:
         * - 0 = water
         * - 1 = fertilizer
         * - 2 = pruning
         */
        void decay(int decayIndex)  ;

        /**
         * @brief Checks if plant is dead based on health thresholds.
         * @return true if plant is dead, false otherwise
         */
        bool isDead() ; 

} ;


#endif // HEALTH_H
