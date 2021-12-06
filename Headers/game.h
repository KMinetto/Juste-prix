#pragma once

#include "constants.h"

/**
 * @brief Traitement pour voir si le nombre proposé est le même que le nombre à deviner
 * 
 * @param numberToGuess 
 * @param proposal 
 */
void guessingNumber(int numberToGuess, int max = MAXIMAL_PRICE);
void playThreeGames();