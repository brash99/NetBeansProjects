/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GVCoin.h
 * Author: brash
 *
 * Created on October 8, 2022, 8:34 AM
 */

#ifndef GVCOIN_H
#define GVCOIN_H

#include <stdio.h>
#include <stdbool.h>

typedef struct GVCoin_struct {
    bool isHeads;
    int flips;
    int heads;
} GVCoin;

GVCoin InitGVCoin(int seed);
GVCoin Flip(GVCoin coin);
int NumFlips(GVCoin coin);
int NumHeads(GVCoin coin);
int NumTails(GVCoin coin);
bool IsHeads(GVCoin coin);

#endif /* GVCOIN_H */

