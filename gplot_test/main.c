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

int main(int argc, char** argv) {
    
    /* define the maximum number of iteration values as a constant integer */
    const int N_max = 20;
    
    /* create arrays to hold the number of iterations, the value of e for this
     iteration, the differences between the exact value and our calculation, and
     our prediction for the difference based on diff = A/N_iterations */
    double x[N_max], y[N_max], e[N_max], ytheory[N_max];
    
    /* Loop over the iterations, from 0 to the maximum number*/
    for (int i=0; i<N_max; i++) {
        
        x[i] = 10*i;
        y[i] = x[i]*x[i];
        ytheory[i] = 0.9*x[i]*x[i];
        e[i] = 10*sqrt(y[i]);
     
    }
    
    /* gplot_basic(x,y,N_max,"GNUPlot Basic Test","X","Y","My Data","Unix"); */
    /* gplot_basicline(x,y,N_max,"GNUPlot Basic Test with Line","X","Y","My Data","Unix"); */
    
    /* gplot_errors(x,y,e,N_max,"GNUPlot Errors Test","X","Y","My Data","Unix"); */
    /* gplot_errorsline(x,y,e,N_max,"GNUPlot Errors Test with Line","X","Y","My Data","Unix"); */
    
    /* gplot_theory(x,y,ytheory,N_max,"GNUPlot Data + Theory Test","X","Y","My Data","My Theory","Unix"); */
    /* gplot_theoryline(x,y,ytheory,N_max,"GNUPlot Data + Theory with Line","X","Y","My Data","My Theory","Unix"); */
    
    gplot_errorstheory(x,y,e,ytheory,N_max,"GNUPlot Data + Errors + Theory","X","Y","My Data","My Theory","Unix");
    /* gplot_errorstheoryline(x,y,e,ytheory,N_max,"GNUPlot Data + Errors + Theory with Line","X","Y","My Data","My Theory","Unix"); */
    
    return (EXIT_SUCCESS);
    
}