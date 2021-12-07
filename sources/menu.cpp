// Libraries
#include <iostream>
#include <array>

// Imported files .h
#include "../Headers/constants.h"
#include "../Headers/menu.h"
#include "../Headers/game.h"

using namespace std;

MenuChoice askMenuChoice() {
    char userChoice;
    cin >> userChoice;
    
    if (userChoice == static_cast<char>(MenuChoice::PLAY) || userChoice == static_cast<char>(MenuChoice::QUIT)
        || userChoice == static_cast<char>(MenuChoice::SCORES)) {
        return static_cast<MenuChoice>(userChoice);
    } else {
        return MenuChoice::INCORRECT;
    }
}

void menuChoices() {
    cout << static_cast<char>(MenuChoice::PLAY) << ": Jouer" << endl;
    cout << static_cast<char>(MenuChoice::SCORES) << ": Afficher les scores" << endl;
    cout << static_cast<char>(MenuChoice::QUIT) << ": Quitter" << endl;
}

void displayMenu() {
    auto scores = ArrayScores{0, 0, 0};
    auto currentIndex{0};

    bool continueGame{true};

    while(continueGame) {
        menuChoices();

        auto choice = askMenuChoice();

        switch (choice) {
            case MenuChoice::PLAY:
                scores[currentIndex] = guessingNumber(3000, MAXIMAL_PRICE);
                currentIndex = (currentIndex + 1) % SCORES;
                break;
            case MenuChoice::SCORES:
                displayScores(scores);
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