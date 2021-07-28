/*
 * Program to calculate e, and then plot the results as a function of the
 * number of iterations
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 27, 2021, 12:29 PM
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

    double N[101];
    const int N_max = 100;
    double e_accurate = 2.718281828;
    double e[N_max], diff[N_max];
    
    for (int i=0; i<N_max; i++) {
        N[i] = i*15000+15000;
        e[i] = elim(N[i]);
        diff[i] = e_accurate - e[i];
        printf ("Iterations = %d, e_approx = %9.8f, e_exact = %9.8f, difference = %9.8f \n",i,e[i],e_accurate,diff[i]);
    }
    
    printf ("N_final = %9.1f, e_approx = %9.8f, e_exact = %9.8f, difference = %9.8f \n",N[N_max-1],e[N_max-1],e_accurate,diff[N_max-1]);
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    fprintf(gnuplot, "set logscale xy\n");
    fprintf(gnuplot, "plot '-'\n");
    for (int i = 0; i < N_max; i++) {
        fprintf(gnuplot, "%g %g\n", N[i], diff[i]);
    }
    fprintf(gnuplot, "e\n");
    fflush(gnuplot);
    
    return (EXIT_SUCCESS);
    
}