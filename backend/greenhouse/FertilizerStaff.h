#ifndef FERTILIZERSTAFF_H
#define FERTILIZERSTAFF_H

#include <string>
#include "GreenhouseStaff.h"
using namespace std;

/**
 * @class FertilizerStaff
 * @brief Concrete observer class for staff responsible for fertilizing plants.
 * 
 * This class represents greenhouse staff members who are specifically responsible
 * for applying fertilizer to plants. It implements the GreenhouseStaff interface 
 * and responds to notifications when plants require fertilizing care (careType == "fertilizer").
 */
class FertilizerStaff : public GreenhouseStaff {
    public:

        /**
         * @brief Updates the fertilizer staff about a plant's care requirements.
         * 
         * This method is called when a plant notifies observers about its care needs.
         * The fertilizer staff will respond if the care type indicates that fertilizing 
         * is required.
         * 
         * @param careType The type of care required (checks for "fertilizer")
         * @param plant Pointer to the plant that needs care
         */
        void update(string& careType, Plant* plant);
};

#endif