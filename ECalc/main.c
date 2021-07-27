/*
 * Program to calculate e to a specified tolerance.
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 27, 2021, 4:09 AM
 */

#include <stdio.h>
#include <stdlib.h>

double power(double x, int N) {
    double result=1.0;
    for (int i=0; i<N; i++){
        result = result*x;
    }
    return result;
}

double elim(int N) {
    double x = 1.0+1.0/N;
    return power(x,N);
}

int main(int argc, char** argv) {
    double threshold = 1.0E-8;
    double diff = 1000.0;
    int N = 1;
    double e_accurate = 2.718281828;
    double e;
    
    while (diff > threshold) {
        e = elim(N);
        diff = e_accurate - e;
        N = N + 100000;
        printf ("e_approx = %9.8f, e_exact = %9.8f, difference = %9.8f \n",e,e_accurate,diff);
    }
    
    printf ("Iterations = %d, e_approx = %9.8f, e_exact = %9.8f, difference = %9.8f \n",N,e,e_accurate,diff);
    
    return (EXIT_SUCCESS);
}

