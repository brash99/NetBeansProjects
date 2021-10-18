/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 26, 2021, 7:21 PM
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The simplest program, which prints out "Hello World!!!" 
 */

int main(int argc, char** argv) {
    
    printf("Hello World!!!!\n");
    
    int i;
    double a = 2.0;
    double b = 2.5;
    i = (int)(a*b*b);
    
    printf("%d",i);
    
    return (EXIT_SUCCESS);
}

