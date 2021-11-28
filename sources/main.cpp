// Libraries
#include<iostream>

// Imported files

// Namespaces
using namespace std;

/**
 * @brief Traitement pour voir si le nombre proposé est le même que le nombre à deviner
 * 
 * @param numberToGuess 
 * @param proposal 
 */
void guessingNumber(int numberToGuess, int proposal) {    
    auto trials{0};

    cout << "Veuillez deviner le nombre à deviner :" << endl;

    do {
        cin >> proposal;
        if (proposal >= 0) {
            trials++;
            if (proposal > numberToGuess) {
                cout << "Le nombre est plus petit !" << endl;
            } else if (proposal < numberToGuess) {
                cout << "Le nombre est plus grand !" << endl;
            } else if (proposal == numberToGuess) {
                cout << "Bravo !" << endl;
            }
        }

    } while (proposal != numberToGuess && proposal >= 0);

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
    auto choice{'j'};
    cout << "j: Jouer" << endl;
    cout << "q: Quitter" << endl;

    cin >> choice;

    switch (choice) {
    case 'j':
        cout << "C'est partie !" << endl;
        for (auto numberToGuess : {2'018, 42, 1984}) {
            auto proposal{0};
            guessingNumber(numberToGuess, proposal);
        }
        break;
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