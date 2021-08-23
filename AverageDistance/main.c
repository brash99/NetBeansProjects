/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 22, 2021, 4:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gplot.h>
#include <sodium.h>

/*
 * 
 */
int main(int argc, char** argv) {
       
    double sum = 0.0;
    const int N_max = 5000000;
    
    double distance[N_max];
    
    for (int i=0; i<N_max; i++) {
        double x1 = 1.0*randombytes_uniform(RAND_MAX)/RAND_MAX;
        double x2 = 1.0*randombytes_uniform(RAND_MAX)/RAND_MAX;
        double y1 = 1.0*randombytes_uniform(RAND_MAX)/RAND_MAX;
        double y2 = 1.0*randombytes_uniform(RAND_MAX)/RAND_MAX;
        double dist = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
        distance[i]=dist*100.0;
        /* printf("%d         %g\n",i,dist); */
        sum = sum + dist;
    }
    
    int binwidth = 1;
    int binstart = 0;
    /* gplot_hist_basic(distance,N_max,binwidth,binstart,"Average Distance Simulation","Distance x 100","Simulated Data","Unix"); */
    
    double avg = sum/N_max;
    printf("Average =          %g\n",avg);
    
    return (EXIT_SUCCESS);
}

