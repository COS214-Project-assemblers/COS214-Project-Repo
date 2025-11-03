/**
 * @file MenuOption.h
 * @brief Base class for menu command options
 * @author Gerard Jordaan
 */

#ifndef M_OPTION
#define M_OPTION

#include "Game.h"
#include "Logger.h"

/**
 * @class MenuOption
 * @brief Abstract base class for menu command options
 * @details Implements the Command pattern to encapsulate game operations
 * as executable commands with optional logging capabilities.
 * 
 * @see NewGameOption
 * @see ExitGameOption
 */
class MenuOption {
    protected:
        /**
         * @brief Reference to Game object for command execution
         */
        Game* game;
        
        /**
         * @brief Optional reference to Logger for command logging
         */
        Logger* logger;

    public:
        /**
         * @brief Constructor - initializes game and logger references
         * @param[in] game Game object reference
         * @param[in] logger Optional reference to Logger object, default is nullptr
         */
        MenuOption(Game* game, Logger* logger = nullptr);

        /**
         * @brief Pure virtual execute method to be implemented by subclasses
         */
        virtual void execute() = 0;

        /**
         * @brief Virtual destructor for proper cleanup
         */
        virtual ~MenuOption() = default;
};

#endif