// Libraries
#include <iostream>

// Imported Files
#include "../Headers/constants.h"
#include "../Headers/game.h"

using namespace std;

int guessingNumber(int numberToGuess, int max) { 
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

    return trials;
}

void displayScores(ArrayScores &scores) {
    cout << "Scores des trois dernières parties : " << endl;
        for (auto score : scores) {
        if (score == 0) {
            cout << "-" << endl;
        } else {
            cout << score << " essais" << endl;
        }
    }
}
