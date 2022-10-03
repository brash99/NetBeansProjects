/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 7, 2021, 10:46 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gplot.h>
#include <mtwister.h>

/*
 * Simulate online solitaire
 */
int main(int argc, char** argv) {
    
    /* Initial data */
    double p_i = 0.520;
    int N_i = 1000;
    double p_m = 0.5733;
    int N_m = 1500;
    
    int N_i_won = N_i*p_i;
    int N_m_won = N_m*p_m;
    
    int N_diff = N_m_won - N_i_won;
    double p_f = N_diff*1.0/(N_m-N_i)*1.0;
    
    printf ("%d %d %d %g\n",N_i_won,N_m_won,N_diff,p_f);
    printf ("Awwww ... crap!\n\n");
    
    N_i_won = round(N_i*p_i);
    N_m_won = round(N_m*p_m);
    N_diff = N_m_won - N_i_won;
    p_f = N_diff*1.0/(N_m-N_i)*1.0;
    
    printf ("%d %d %d %g\n",N_i_won,N_m_won,N_diff,p_f);
    printf ("Yea buddy!\n\n");
    
    /* So now, we have the base numbers for the simulation */
    
    /* The first random number generator we will look at is rand(), which
     * is part of almost all C/C++ implementations.  It is not a great PRNG!
     * 
     * It uses the Linear Congruential Algorithm
     * 
     * We start by setting the "seed" of the random number generator, using
     * the current time ... that way we will get a different sequence of 
     * random numbers every time we run the program! */
    
    srand(1); /* for testing purposes */
    /* srand(time(0)); */
    
    long int seed = 1;
    long int a = 16807;
    long int c = 0;
    /* long int a = 1103515245; */
    /* long int c = 12345; */
    long int m = pow(2,31);
    
    long int mask = 0x7fffffff;
    
    
    printf("a = %ld c = %ld m = %ld\n\n",a,c,m);
    
    /* generate some random numbers */
    
    for (int i =0; i<10; i++) {
        seed = (a*seed + c) % m;
        /* seed = seed & mask; */
  
        int rnum = rand();
        double rnum_double = 1.0*rnum/RAND_MAX;
        printf("%ld %d         %g\n",seed,rnum,rnum_double);
    }
   
    printf("\nRange of random integers is between 0 and %d\n\n",RAND_MAX);
    
    /* 
     * 
     * As mentioned above rand() is not appropriate for any application where
     * one wants either crypto level security, or honestly in any application
     * where one is going to be generating 2^32 random numbers or more ... 
     * the Lin. Cong. algorithm starts to repeat after that many random numbers
     * on basically every archtecture.  So, my idea is just never use it! 
     * 
     * Instead, we will use an algorithm called Mersenne Twister ... it's really
     * good and really fast, and does not repeat over a VERY long scale.  it is
     * pretty safe for crypto applications.  There are better ones, but it is
     * more than adequate for our purposes.
     * 
     * I have included a version of it in the gplot project, and so linking to
     * that library will get you this random number generator as well!
     
    */
    
    MTRand r = seedRand((unsigned)time(0)); // seed the random number generator with system time
                                            // so that sequence is different each time we run the program
                                            // seedRand() returns an object of type MTRand
                                            // MTRand is a C struct - see the header file for details 
    
    // Generate ten random numbers between 0 and 1
    for (int i=0; i<10; i++) {
        double rnum = genRand(&r); // genRand returns a double
        printf("%g\n",rnum);
    }
    
    /* So, we can generate a UNIFORM distribution of random numbers between 0 and 1*/
    
    /* OK, let's simulate some solitaire games */
    
    int N_won_current = N_m_won;
    int N_current = N_m;
    double p_current = 1.0*N_won_current/N_current;
    double game_number[2000];
    double p_running[2000];
    
    int counter=0;
    while (p_current<0.60) {
        double rnum_double = genRand(&r);
        if (rnum_double < p_f) {
            N_won_current++;
        }
        N_current++;
        p_current = 1.0*N_won_current/N_current;
        game_number[counter] = N_current;
        p_running[counter] = p_current;
        counter++;
    }
    
    printf("Reached 60 percent!!!!! \n");
    printf ("%d %d %d %g\n",counter,N_won_current,N_current,p_current);
    printf ("Yea buddy!\n\n");
    
    /* gplot_basic(game_number,p_running,counter,"Running Win Percentage","Game Number","Win Percentage","Simulated Data","Unix"); */
    
    /* OK, so now let's simulate the process many times, to see the 
     DISTRIBUTION of results */
    
    const int N_simulations = 20000;
    double N_final[N_simulations];
    double sim_number[N_simulations]; 
    
    for (int j=0;j<N_simulations;j++){
        N_won_current = N_m_won;
        N_current = N_m;
        p_current = 1.0*N_won_current/N_current;
    
        while (p_current<0.60) {
            double rnum_double = genRand(&r);
            if (rnum_double < p_f) {
                N_won_current++;
            }
            N_current++;
            p_current = 1.0*N_won_current/N_current;
        }
        
        N_final[j]=N_current;
        sim_number[j]=j;
    }
    
    int binwidth = 10;
    int binstart = 1600;
    
    gplot_basic(sim_number,N_final,N_simulations,"Solitaire Simulation","Simulation Number","Number of Games to 60 PerCent","Simulated Data","Windows"); 
    gplot_hist_basic(N_final,N_simulations,binwidth,binstart,"Solitaire Simulation","Number of Games to 60 PerCent","Simulated Data","Windows"); 
    
    return (EXIT_SUCCESS);
}

