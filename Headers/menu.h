#pragma once

// Enumeration
enum class MenuChoice {
    PLAY = 'a', // Play one game
    PLAY_EASY = 'b', // Maximum 1'000
    PLAY_THREE_GAMES = 'c',
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