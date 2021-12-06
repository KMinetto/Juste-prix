// Libraries
#include <iostream>

// Imported files .h
#include "../Headers/constants.h"
#include "../Headers/menu.h"
#include "../Headers/game.h"

using namespace std;

MenuChoice askMenuChoice() {
    char userChoice;
    cin >> userChoice;
    
    if (userChoice == static_cast<char>(MenuChoice::PLAY) || userChoice == static_cast<char>(MenuChoice::QUIT) || userChoice == static_cast<char>(MenuChoice::PLAY_EASY)
        || userChoice == static_cast<char>(MenuChoice::PLAY_THREE_GAMES)) {
        return static_cast<MenuChoice>(userChoice);
    } else {
        return MenuChoice::INCORRECT;
    }
}

void menuChoices() {
    cout << static_cast<char>(MenuChoice::PLAY) << " Jouer" << endl;
    cout << static_cast<char>(MenuChoice::PLAY_EASY) << " Jouer une partie facile" << endl;
    cout << static_cast<char>(MenuChoice::PLAY_THREE_GAMES) << " Jouer trois parties" << endl;
    cout << static_cast<char>(MenuChoice::QUIT) << " Quitter" << endl;
}

void displayMenu() {
    bool continueGame{true};

    while(continueGame) {
        menuChoices();

        auto choice = askMenuChoice();

        switch (choice) {
            case MenuChoice::PLAY:
                guessingNumber(3000, MAXIMAL_PRICE);
                break;
            case MenuChoice::PLAY_EASY:
                guessingNumber(250, MAXIMAL_PRICE_EASY);
                break;
            case MenuChoice::PLAY_THREE_GAMES:
                playThreeGames();
                break;
            case MenuChoice::QUIT:
                cout << "Au revoir !";
                continueGame = false;
                break;
            case MenuChoice::INCORRECT:
            default:
                EXIT_FAILURE;
        }
    } 
} 