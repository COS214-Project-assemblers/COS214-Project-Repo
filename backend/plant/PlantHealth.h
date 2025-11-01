#ifndef HEALTH_H
#define HEALTH_H


#include <iostream>
#include <mutex>
#include <chrono>
#include <random>

class Plant; // forward declaration

class Health {
    friend class Plant ;
    protected:
        float water;
        float fertalizer;
        float pruning;
        int mature;

        std::mutex mtx;
        std::mt19937 rng;
        std::uniform_int_distribution<int> dist;

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

        std::string getWater();
        std::string getFertilizer();
        std::string getPruning();

        /**
         * @brief Destructor for Health.
         * Currently, no dynamic memory is managed by Health, so this destructor is empty.
         */
        ~Health();

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
        Health* clone()             ;

        /**
         * @brief Computes the overall health score.
         * The health score is a simple additive measure of the plant’s
         * water, fertilizer, and pruning levels.
         * @return The total health score (float), typically in the range [0, 3].
         */
        float healthScore()         ;
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

} ;


#endif // HEALTH_H
