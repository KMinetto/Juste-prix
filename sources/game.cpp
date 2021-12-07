// Libraries
#include <iostream>
#include <chrono>

// Imported Files
#include "../Headers/constants.h"
#include "../Headers/game.h"

using namespace std;

int guessingNumber(int numberToGuess, int max) { 
    auto proposal{0};  
    auto trials{0};

    using Timer = chrono::duration<double>;
    auto begin = chrono::system_clock::now();

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

    auto end = chrono::system_clock::now();
    auto timer = chrono::duration_cast<Timer>(end - begin);

    if (proposal == numberToGuess) {
        cout << "Partie terminée en " << trials << " tentatives !" << endl;
        cout << "Durée de la partie : " << timer.count() << " secondes" << endl;
        if (timer < 30s) {
            cout << "Bravo vous avez gagné !" << endl;
        } else {
            cout << "Vous avez malheureusement mis trop de temps pour trouver la bonne réponse :(" << endl;
        }
    } else {
        cout << "Partie abandonnée !";
    }

    cout << endl;

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