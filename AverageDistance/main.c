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
    
    char myString[32];
    uint32_t rnum1_Sodium;
    uint32_t rnum2_Sodium;
    uint32_t rnum3_Sodium;
    uint32_t rnum4_Sodium;
    
    randombytes_buf(myString, 32);
    /* myString will be an array of 32 random bytes, not null-terminated */
    
    double sum = 0.0;
    const int N_max = 500000;
    
    double distance[N_max];
    
    for (int i=0; i<N_max; i++) {
        rnum1_Sodium = randombytes_uniform(RAND_MAX);
        rnum2_Sodium = randombytes_uniform(RAND_MAX);
        rnum3_Sodium = randombytes_uniform(RAND_MAX);
        rnum4_Sodium = randombytes_uniform(RAND_MAX);
        double rnum1_double_Sodium = 1.0*rnum1_Sodium/RAND_MAX;
        double rnum2_double_Sodium = 1.0*rnum2_Sodium/RAND_MAX;
        double rnum3_double_Sodium = 1.0*rnum3_Sodium/RAND_MAX;
        double rnum4_double_Sodium = 1.0*rnum4_Sodium/RAND_MAX;
        double dist = sqrt(pow((rnum1_double_Sodium-rnum2_double_Sodium),2)+pow((rnum3_double_Sodium-rnum4_double_Sodium),2));
        distance[i]=dist*100.0;
        /* printf("%d         %g\n",i,dist); */
        sum = sum + dist;
    }
    
    int binwidth = 1;
    int binstart = 0;
    gplot_hist_basic(distance,N_max,binwidth,binstart,"Average Distance Simulation","Distance x 100","Simulated Data","Unix"); 
    
    double avg = sum/N_max;
    printf("Average =          %g\n",avg);
    
    return (EXIT_SUCCESS);
}

