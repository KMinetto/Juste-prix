#pragma once

#include <array>
#include "constants.h"

using ArrayScores = std::array<int, SCORES>;

/**
 * @brief Traitement pour voir si le nombre proposé est le même que le nombre à deviner
 * 
 * @param numberToGuess 
 * @param proposal 
 */
int guessingNumber(int numberToGuess, int max = MAXIMAL_PRICE);
void displayScores(ArrayScores &scores);