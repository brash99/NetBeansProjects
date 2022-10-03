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
#include <mtwister.h>
#include <time.h>

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
    int N_trials = 10000000;
    MTRand r = seedRand((unsigned)time(0));
    
    for (int i=0; i<N_trials;i++) {
        int timesteps = 0;
        int sock1 = 1;
        int sock2 = 2;
    
        while (sock1 != sock2) {
            sock1 = 2*genRand(&r);
            sock2 = 3*genRand(&r);
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
    int t1=0,t2=0,t3=0;
    
    for (int i=0; i<N_trials;i++) {
        
        int timesteps = 0;
        int s1,s2,s3;

        s1 = 3*genRand(&r);
        s2 = 3*genRand(&r);
        timesteps = timesteps + 2; // Add two time units for pulling the two socks
        
        if (s1 == s2) {
            t1 = t1 + 1;
            //printf("choice 1: %d %d %d\n",s1,s2,timesteps);
            //continue; // that's it ... we are done.
        } else {
            s3 = 3*genRand(&r);
            timesteps = timesteps + 1; // Add a time unit for pulling the third sock
            if (s3 == s1 || s3 == s2) {
                t2 = t2 + 1;
                timesteps = timesteps + 1; // Add a time unit for putting back the extra sock
                //printf("choice 2: %d %d %d %d\n",s1,s2,s3,timesteps);
            } else {
                t3 = t3 + 1;
                timesteps = timesteps + 3; // Add a time unit for pulling the fourth sock, and two time units for putting back two socks.
                //printf("choice 3: %d %d %d %d\n",s1,s2,s3,timesteps);
            }
        }
        
        //printf("choices = %d %d %d ... timesteps = %d\n",t1,t2,t3,timesteps);
        
        timesum = timesum + timesteps;
        
    }
    
    printf("Probabilities = %g %g %g\n",1.0*t1/N_trials,1.0*t2/N_trials,1.0*t3/N_trials);
    
    printf("Done ... Algorithm 2: Average timesteps = %g\n",1.0*timesum/N_trials);

    return (EXIT_SUCCESS);
}

