// Libraries
#include <iostream>

// Imported files

// Namespaces
using namespace std;

// Contants
const auto MINIMAL_PRICE{0};
const auto MAXIMAL_PRICE{10'000};
const auto MAXIMAL_PRICE_EASY{1'000};

// Enumeration
enum class MenuChoice {
    PLAY = 'a', // Play one game
    PLAY_EASY = 'b', // Maximum 1'000
    PLAY_THREE_GAMES = 'c',
    QUIT = 'q',
    INCORRECT
};

/**
 * @brief Traitement pour voir si le nombre proposé est le même que le nombre à deviner
 * 
 * @param numberToGuess 
 * @param proposal 
 */
void guessingNumber(int numberToGuess, int max) { 
    auto proposal{0};  
    auto trials{0};

    cout << "Veuillez deviner le nombre à deviner :" << endl;

    do {
        cin >> proposal;
        if (proposal >= MINIMAL_PRICE && proposal < max) {
            trials++;
            if (proposal > numberToGuess) {
                cout << "Le nombre est plus petit !" << endl;
            } else if (proposal < numberToGuess) {
                cout << "Le nombre est plus grand !" << endl;
            } else if (proposal == numberToGuess) {
                cout << "Bravo !" << endl;
            }
        }

    } while (proposal != numberToGuess && proposal >= MINIMAL_PRICE);

    if (proposal == numberToGuess) {
        cout << "Partie terminée en " << trials << " tentatives !" << endl;
    } else {
        cout << "Partie abandonnée !";
    }
}

void playThreeGames() {
    cout << "C'est partie !" << endl;
    for (auto numberToGuess : {2'018, 42, 1'984}) {
        guessingNumber(numberToGuess, MAXIMAL_PRICE);
    }
}

/**
 * @brief Ask to the user a choice play or quit
 * 
 * @return MenuChoice 
 */
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

/**
 * @brief Display a menu to play or quit game
 * 
 */
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

int main() {
    cout << "Bienvenue au \"Juste Prix\" !" << endl;

    displayMenu();    

    return EXIT_SUCCESS;
}