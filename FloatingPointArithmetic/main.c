/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 31, 2021, 4:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define REALTYPE double

/*
 * This is a program which demonstrates some of the issues with floating
 * point rounding errors
 * 
 */

// Define a function that calculates the average of a certain number of elements
// of an array.

REALTYPE mean(REALTYPE array[], int size) {
  REALTYPE total = 0.0;
  
  for (int i = 0; i < size; i++) {
    total += array[i];
    printf("array[%d] = %21.19f and total is %21.19f\n", i, array[i], total);
  }
  if (size != 0)
    return total / size;
  else
    return 0.0;
}

int main(int argc, char** argv) {
    
    const int array_size = 10;
    REALTYPE array_value = 10.1;
    
    REALTYPE array[array_size];
    REALTYPE avg;
    
    for (int i = 0; i < array_size; i++) {
        array[i] = array_value;
    }
 
    avg = mean( array, array_size);
    printf("mean is %21.19f\n", avg);
    
    // This is bad!!!!!!!!!!!! comparing two floating point numbers to one
    // another is fraught with peril!
    if (avg == array[0]) {
        printf("array[0] is the mean\n");
    } else {
        printf("array[0] is not the mean\n");
    }
   
    
    // This is a better way ... define a "tolerance" for when you will consider
    // two floating point numbers to be "equal", or at least close enough.
    REALTYPE epsilon = 1.0E-10;
    
    if (fabs(avg -array[0]) < epsilon) {
        printf("array[0] is the mean\n");
    } else {
        printf("array[0] is not the mean\n");
    }
    
    
    // Even really simple things with floating points can be a bit confusing ..
    // Usually this does not matter so much, but sometimes it does, and it is
    // really hard to predict ahead of time when it will and when it will not.
    
    REALTYPE a = 0.10;
    REALTYPE b = 0.20;
    
    REALTYPE c = a + b;
    
    printf ("%21.19f + %21.19f = %21.19f\n",a,b,c);
    
    
    return (EXIT_SUCCESS);
}

