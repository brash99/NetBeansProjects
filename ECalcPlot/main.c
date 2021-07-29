/*
 * Program to calculate e, and then plot the results as a function of the
 * number of iterations.
 * 
 * This serves as a good example of how to create a gnuplot plotting script and data file
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 27, 2021, 12:29 PM
 */

#include <stdio.h>
#include <stdlib.h>

/* Function to calculate x^N */
double power(double x, int N) {
    double result=1.0;
    for (int i=0; i<N; i++){
        result = result*x;
    }
    return result;
}

/* Function to approximate e as e = (1+1/N)^N for large N */
double elim(int N) {
    double x = 1.0+1.0/N;
    return power(x,N);
}

int main(int argc, char** argv) {

    /* define the maximum number of iteration values as a constant integer */
    const int N_max = 200;
    
    /* define the value of e to 9 decimal places */
    double e_accurate = 2.718281828;
    
    /* create arrays to hold the number of iterations, the value of e for this
     iteration, the differences between the exact value and our calculation, and
     our prediction for the difference based on diff = A/N_iterations */
    double N[N_max];
    double e[N_max], diff[N_max], diff_theory[N_max];
    
    /* create variables for the initial calculation, which defines the
     constant A, for our prediction */
    double x0,y0,A;
    
    /* Loop over the iterations, from 0 to the maximum number*/
    for (int i=0; i<N_max; i++) {
        
        N[i] = i*15000+15000;
        e[i] = elim(N[i]);
        diff[i] = e_accurate - e[i];
        
        /* record the initial value at the lowest number of iterations, which
         will define the constant A for future predictions */
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
    
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata = fopen("gnuplotData", "w");
    
    /* Mac OS terminal type */
    fprintf(gnuplot, "set terminal x11\n");
    /* Windows 10 terminal type */
    /* fprintf(gnuplot, "set terminal qt\n"); */
    
    /* Set logscale, title, and axis labels */
    fprintf(gnuplot, "set logscale xy\n");
    fprintf(gnuplot, "set key font 'Arial,16'\n");
    fprintf(gnuplot, "set tics font 'Arial,12'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set title 'Calculation of e' font 'Arial,20'\n");
    fprintf(gnuplot, "set xlabel 'Number of iterations' font 'Arial,16'\n");
    fprintf(gnuplot, "set ylabel 'Difference from exact value' font 'Arial,16'\n");
    
    /* plot command - plot the data as points, and the prediction as a solid line (green)*/
    
    fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5\n");
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linewidth 2\n");
    fprintf(gnuplot, "plot 'gnuplotData' using 1:2 title 'Approximation' with points linestyle 1, 'gnuplotData' using 1:3 title 'Prediction' with lines linestyle 2\n");
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < N_max; i++) {
        fprintf(gnudata, "%g %g %g\n", N[i], diff[i], diff_theory[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata);
    
    return (EXIT_SUCCESS);
    
}