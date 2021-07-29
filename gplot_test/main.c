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

/*
 * 
 */
int main(int argc, char** argv) {
    
    /* define the maximum number of iteration values as a constant integer */
    const int N_max = 200;
    
    /* create arrays to hold the number of iterations, the value of e for this
     iteration, the differences between the exact value and our calculation, and
     our prediction for the difference based on diff = A/N_iterations */
    double x[N_max], y[N_max];
    
    /* Loop over the iterations, from 0 to the maximum number*/
    for (int i=0; i<N_max; i++) {
        
        x[i] = -100+i;
        y[i] = x[i]*x[i]*x[i];
     
    }
   
    gplot_basic(x,y,N_max,"GNUPlot Test","X","Y","My Data","Unix");
    
    return (EXIT_SUCCESS);
    
}