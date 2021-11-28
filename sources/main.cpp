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
        trials++;
        cin >> proposal;

        if (proposal > numberToGuess) {
            cout << "Le nombre est plus petit !" << endl;
        } else if (proposal < numberToGuess) {
            cout << "Le nombre est plus grand !" << endl;
        } else if (proposal == numberToGuess) {
            cout << "Vous avez gagné !" << endl << "Il vous a fallu " << trials << " essais pour trouver le juste prix !" << endl;
        }

    } while (proposal != numberToGuess);
}

int main() {
    cout << "Bienvenue au \"Juste Prix\" !" << endl;

    auto numberToGuess{3'784};
    auto proposal{0};
    
    guessingNumber(numberToGuess, proposal);

    return 0;
}