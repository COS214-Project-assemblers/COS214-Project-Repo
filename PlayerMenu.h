#ifndef P_MENU
#define P_MENU

// Forward declaration, ok to do so since using MenuOption*
class MenuOption;

class PlayerMenu {
    private:
        MenuOption* menuOption;
    public:
        void setMenuOption(MenuOption* option);
        void executeOption();
        ~PlayerMenu();
};

#endif // P_MENU