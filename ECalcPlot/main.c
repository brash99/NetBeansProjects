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

    const int N_max = 1200;
    
    double N[N_max];
    double e_accurate = 2.718281828;
    double e[N_max], diff[N_max], diff_theory[N_max];
    
    double x0,y0,A;
    
    for (int i=0; i<N_max; i++) {
        N[i] = i*15000+15000;
        e[i] = elim(N[i]);
        diff[i] = e_accurate - e[i];
        if (i==0) {
            x0 = N[i];
            y0 = diff[i];
            A = x0*y0;
        }
        diff_theory[i] = A/N[i];
        printf ("Iterations = %d, e_approx = %9.8f, e_exact = %9.8f, difference = %9.8f \n",i,e[i],e_accurate,diff[i]);
    }
    
    printf ("N_final = %9.1f, e_approx = %9.8f, e_exact = %9.8f, difference = %9.8f \n",N[N_max-1],e[N_max-1],e_accurate,diff[N_max-1]);
    
    printf ("Initial x,y value = %9.8f,%9.8f \n",x0,y0);
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata = fopen("gnuplotData", "w");
    fprintf(gnuplot, "set terminal x11\n");
    fprintf(gnuplot, "set logscale xy\n");
    fprintf(gnuplot, "set title 'Calculation of e'\n");
    fprintf(gnuplot, "set xlabel 'Number of iterations'\n");
    fprintf(gnuplot, "set ylabel 'Difference from exact value'\n");
    fprintf(gnuplot, "plot 'gnuplotData' using 1:2, 'gnuplotData' using 1:3 with lines linestyle 2\n");
    for (int i = 0; i < N_max; i++) {
        fprintf(gnudata, "%g %g %g\n", N[i], diff[i], diff_theory[i]);
    }
    fflush(gnuplot);
    fflush(gnudata);
    
    return (EXIT_SUCCESS);
    
}