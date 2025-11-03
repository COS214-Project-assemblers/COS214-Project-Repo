/**
 * @file WaterStaff.h
 * @brief Concrete observer for watering staff in greenhouse
 */
#ifndef WATERSTAFF_H
#define WATERSTAFF_H

#include <string>
#include "GreenhouseStaff.h"
using namespace std;

/**
 * @class WaterStaff
 * @brief Concrete observer class for staff responsible for watering plants.
 * 
 * This class represents greenhouse staff members who are specifically responsible
 * for watering plants. It implements the GreenhouseStaff interface and responds
 * to notifications when plants require watering care (careType == "water").
 * 
 * @see GreenhouseStaff
 */
class WaterStaff : public GreenhouseStaff {
    public:

        /**
         * @brief Updates the water staff about a plant's care requirements.
         * 
         * This method is called when a plant notifies observers about its care needs.
         * The water staff will respond if the careType indicates that watering is required.
         * 
         * @param careType The type of care required (checks for "water")
         * @param plant Pointer to the plant that needs care
         */
        void update(string& careType, Plant* plant);
};

#endif