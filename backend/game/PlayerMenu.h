/**
 * @file PlayerMenu.h
 * @brief Header file for PlayerMenu class.
 *  PlayerMenu is the Invoker participant in the 
 *  command design pattern
 * @author Gerard Jordaan
 */
#ifndef P_MENU
#define P_MENU

// Forward declaration, ok to do so since using MenuOption*
class MenuOption;

/**
 * @class PlayerMenu
 * @brief Creates object that holds and then executes MenuOption
 */
class PlayerMenu {
    private:
	/**
	 * @brief Attribute that holds MenuOption reference.
	 *  set in setMenuOption method
	 *  used in executeOption to invoke MenuOption execute method
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
	 * @brief Frees mem allocated to menuOption attr
	 */
        ~PlayerMenu();
};

#endif // P_MENU
