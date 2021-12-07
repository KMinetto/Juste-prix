#pragma once

// Enumeration
enum class MenuChoice {
    PLAY = 'a', // Play one game
    SCORES = 's',
    QUIT = 'q',
    INCORRECT
};

/**
 * @brief Ask to the user a choice play or quit
 * 
 * @return MenuChoice 
 */
MenuChoice askMenuChoice();
void menuChoices();
void displayMenu();