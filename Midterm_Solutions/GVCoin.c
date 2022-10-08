/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "GVCoin.h"

GVCoin InitGVCoin(int seed) {
	srand(seed);   // Set seed value for ramdom numbers
	GVCoin coin;
	coin.heads = 0;
	coin.flips = 0;
	coin.isHeads = 1;
	return coin;
}

GVCoin Flip(GVCoin coin) {
	coin.isHeads = rand() % 2;
	coin.flips++;
	if (coin.isHeads) {
		coin.heads++;
	}
	return coin;
}

int NumFlips(GVCoin coin) {
    return coin.flips;
}

int NumHeads(GVCoin coin) {
    return coin.heads;
}

int NumTails(GVCoin coin) {
    return coin.flips - coin.heads;
}

bool IsHeads(GVCoin coin) {
    return coin.isHeads;
}

