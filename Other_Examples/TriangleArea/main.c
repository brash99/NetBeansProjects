/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 3, 2021, 11:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gplot.h>

/* Define a function, of type double, that will take the x-value and return
 the triangle area at that x-value */
double area(double xval) {
    return 12.0 + 3.0/2.0*xval + 24.0/xval;
}


int main(int argc, char** argv) {
    
    /* Define the number of h-values where we will test the 
     * numerical precision */
    const int N_max = 10000;
    double n_max_real = 1.0*N_max;
    
    /* Define some arrays to hold the values of x and the triangle area */
    double x[N_max], a[N_max];
    
    for (int i=0; i<N_max; i++) {
        x[i] = 3.5 + i*1.0/(n_max_real-1.0);
        a[i] = area(x[i]);
        /* printf("%17.15f %17.15f\n",x[i],a[i]); */
    }
    
    gplot_basicline(x,a,N_max,"Numerical Calculation of Triangle Area",
            "x","Area","My Data","Unix");

    return (EXIT_SUCCESS);
}

