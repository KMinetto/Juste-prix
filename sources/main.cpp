// Libraries
#include <iostream>

// Imported files

// Namespaces
using namespace std;

// Enumeration
enum class MenuChoice {
    PLAY = 'j',
    QUIT = 'q',
    INCORRECT
};

/**
 * @brief Traitement pour voir si le nombre proposé est le même que le nombre à deviner
 * 
 * @param numberToGuess 
 * @param proposal 
 */
void guessingNumber(int numberToGuess, int proposal) {   
    const auto MINIMAL_PRICE{0};
    auto trials{0};

    cout << "Veuillez deviner le nombre à deviner :" << endl;

    do {
        cin >> proposal;
        if (proposal >= MINIMAL_PRICE) {
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
        cout << "Partie terminée en " << trials << " tentatives !";
    } else {
        cout << "Partie abandonnée !";
    }
}

/**
 * @brief Display a menu to play or quit game
 * 
 */
void displayMenu() {
    cout << static_cast<char>(MenuChoice::PLAY) << " Jouer" << endl;
    cout << static_cast<char>(MenuChoice::QUIT) << " Quitter" << endl;

    auto choice{MenuChoice::PLAY};
    char userChoice;
    cin >> userChoice;
    
    if (userChoice == static_cast<char>(MenuChoice::PLAY) || userChoice == static_cast<char>(MenuChoice::QUIT)) {
        choice = static_cast<MenuChoice>(userChoice);
    } else {
        choice = MenuChoice::INCORRECT;
    }
    

    switch (choice) {
    case MenuChoice::PLAY:
        cout << "C'est partie !" << endl;
        for (auto numberToGuess : {2'018, 42, 1'984}) {
            auto proposal{0};
            guessingNumber(numberToGuess, proposal);
        }
        break;
    case MenuChoice::QUIT:
    case MenuChoice::INCORRECT:
    default:
        cout << "Au revoir !";
        break;
    }

}

int main() {
    cout << "Bienvenue au \"Juste Prix\" !" << endl;

    displayMenu();    

    return 0;
}