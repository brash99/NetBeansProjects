/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on October 14, 2022, 9:59 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct Restaurant_struct {
    char name[20];
    int rating;
    char price[5];
    char cuisine[30];
    int id;
} Restaurant;

int main(int argc, char** argv) {
    
    Restaurant moes;
    Restaurant schooners;
    Restaurant mickeydees;
    
    moes.rating = 3;

    return (EXIT_SUCCESS);
}

