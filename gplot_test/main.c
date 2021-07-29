/*
 * Test program for gplot library
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 29, 2021, 8:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <gplot.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    /* define the maximum number of iteration values as a constant integer */
    const int N_max = 200;
    
    /* create arrays to hold the number of iterations, the value of e for this
     iteration, the differences between the exact value and our calculation, and
     our prediction for the difference based on diff = A/N_iterations */
    double x[N_max], y[N_max], e[N_max];
    
    printf ("here 1\n");
    
    /* Loop over the iterations, from 0 to the maximum number*/
    for (int i=0; i<N_max; i++) {
        
        x[i] = i;
        y[i] = x[i]*x[i];
        e[i] = sqrt(y[i]);
     
    }
    
    printf ("here 2\n");
   
    gplot_errors(x,y,e,N_max,"GNUPlot Errors Test","X","Y","My Data","Unix");
    
    printf ("here 3\n");
    
    return (EXIT_SUCCESS);
    
}