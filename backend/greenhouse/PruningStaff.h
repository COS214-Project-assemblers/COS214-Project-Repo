#ifndef PRUNINGSTAFF_H
#define PRUNINGSTAFF_H

#include <string>
#include "GreenhouseStaff.h"
using namespace std;

/**
 * @class PruningStaff
 * @brief Concrete observer class for staff responsible for pruning plants.
 *
 * This class represents greenhouse staff members who are specifically responsible
 * for pruning plants. It implements the GreenhouseStaff interface
 * and responds to notifications when plants require pruning care (careType == "pruning").
 */
class PruningStaff : public GreenhouseStaff {
    public:
        /**
         * @brief Updates the pruning staff about a plant's care requirements.
         *
         * This method is called when a plant notifies observers about its care needs.
         * The pruning staff will respond if the care type indicates that pruning
         * is required.
         *
         * ADDITIONAL FUNCTIONALITY:
         * The health class's HandlePruning increments maturity
         * when Health.maturity == 3 - then the plant is deemed "mature"
         * the value "3" was arbitrarily selected
         *
         * @param careType The type of care required (checks for "pruning")
         * @param plant Pointer to the plant that needs care
         */
        void update(string& careType, Plant* plant);
};

#endif
