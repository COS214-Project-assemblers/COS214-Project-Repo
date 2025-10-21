#include "PlayerMenu.h"
#include "MenuOption.h"

void PlayerMenu::setMenuOption(MenuOption* option) {
    if (menuOption != nullptr) {
        delete menuOption;
        menuOption = nullptr;
    }
    this->menuOption = option;
}

void PlayerMenu::executeOption() {
    try {
        menuOption->execute();
    } catch (const std::exception &e) {
        // Rethrow
        throw e;
    }
}

PlayerMenu::~PlayerMenu() {
    if (menuOption != nullptr) {
        delete menuOption;
    }
}