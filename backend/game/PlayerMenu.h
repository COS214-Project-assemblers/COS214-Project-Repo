/**
 * @file PlayerMenu.h
 * @brief Header file for PlayerMenu class - Command pattern invoker
 * @author Gerard Jordaan
 * @details PlayerMenu is the Invoker participant in the Command design pattern
 */

#ifndef P_MENU
#define P_MENU

#include <stdexcept>

class MenuOption;

/**
 * @class PlayerMenu
 * @brief Invoker class that holds and executes MenuOption commands
 * @details Manages and executes command objects following the Command pattern.
 * Separates command invocation from command execution.
 * 
 * @see MenuOption
 */
class PlayerMenu {
    private:
		/**
         * @brief Currently set menu option command
         * @details Set via setMenuOption method and executed via executeOption
         */
        MenuOption* menuOption = nullptr;

    public:
		/**
		 * @brief Setter for menuOption attribute
		 * @param[in] option MenuOption* reference
		 */
		void setMenuOption(MenuOption* option);

		/**
		 * @brief Invokes execute() method on menuOption attribute
		 */
		void executeOption();

		/**
         * @brief Destructor - cleans up allocated menu option
         */
        ~PlayerMenu();
};

#endif
