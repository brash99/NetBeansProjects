/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 25, 2021, 6:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gplot.h>
#include <sodium.h>

/*
 * Program to simulate sock pulling from a drawer
 * 
 * There are three colors of socks ... how long does it take to find a
 * matching pair of socks?
 * 
 */
int main(int argc, char** argv) {
    
    // Algorithm 1:  Choose two socks randomly from the drawer.  If they match,
    // then we are done.  If not, put them back, and pull two more.
    
    int timesum = 0;
    int N_trials = 1000000;
    
    for (int i=0; i<N_trials;i++) {
        int timesteps = 0;
        int sock1 = 1;
        int sock2 = 2;
    
        while (sock1 != sock2) {
            sock1 = randombytes_uniform(3);
            sock2 = randombytes_uniform(3);
            //printf("%d %d\n",sock1,sock2);
            timesteps = timesteps + 2;
            if (sock1 != sock2) {
                timesteps = timesteps + 2;
            }
        }
        
        timesum = timesum + timesteps;
        
    }
    
    printf("Done ... Algorithm 1: Average timesteps = %g\n",1.0*timesum/N_trials);
    
    // Algorithm 2:  Choose socks, keeping them out until a match is found. Then, return unused socks.
    
    timesum = 0;
    for (int i=0; i<N_trials;i++) {
        int timesteps = 0;
        int s[4];
    
        s[0] = randombytes_uniform(3);
        s[1] = randombytes_uniform(3);
        timesteps = timesteps + 2;
        if (s[0] == s[1]) {
            //printf("Done ... Algorithm 2: timesteps = %g\n",1.0*timesteps); 
        } else {
            s[2] = randombytes_uniform(3);
            timesteps = timesteps + 1;
            if (s[2] == s[1] || s[2] == s[0]) {
                timesteps = timesteps + 1;
                //printf("Done ... Algorithm 2: timesteps = %g\n",1.0*timesteps);
            } else {
                timesteps = timesteps + 3;
                //printf("Done ... Algorithm 2: timesteps = %g\n",1.0*timesteps);
            }
        }
        
        timesum = timesum + timesteps;
        
    }
    
    printf("Done ... Algorithm 2: Average timesteps = %g\n",1.0*timesum/N_trials);

    return (EXIT_SUCCESS);
}

