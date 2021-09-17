/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 4, 2021, 10:02 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <gplot.h>
#include <time.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
/*
 * 
 */
int main(int argc, char** argv) {
    
    clock_t t;
    t = clock();
    printf("%ju\n",(uintmax_t)t/CLOCKS_PER_SEC);
    
    const int N_max = 9;
    int nexp[] = {2,3,4,5,6,7,8,9,10};
    long n[N_max];
    double nd[N_max];
    double sum_up[N_max];
    double sum_down[N_max];
    double diff_up[N_max];
    double diff_down[N_max];
    
    clock_t start,end;
    double cpu_time_used[N_max];
    
    double sum_exact = pow(M_PI,2)/6.0;
    
    for (int i = 0; i<N_max; i++) {
        n[i] = pow(10,nexp[i]);
        sum_up[i] = 0.0;
        sum_down[i] = 0.0;
    }
    
    for (int i = 0; i<N_max; i++) {
        start = clock();
        //printf("sum up i = %d\n",i);
        for (unsigned long long j = 1; j <= n[i]; j++) {
            //if (j%10000000 == 0) {
            //    printf("%d %llu\n",i,j);
            //}
            sum_up[i]+= 1.0/pow(j,2);
        }
        end = clock();
        cpu_time_used[i]=((double) (end-start))/CLOCKS_PER_SEC;
        //printf("CPU Time Taken = %g\n",cpu_time_used[i]);
    }
    
    for (int i = 0; i<N_max; i++) {
        //printf("sum down i = %d\n",i);
        for (unsigned long long j = n[i]; j >= 1; j--) {
            sum_down[i]+= 1.0/pow(j,2);
            //if (j%10000000 == 0) {
            //    printf("%d %llu\n",i,j);
            //}
        }
    }
    
    for (int i = 0; i<N_max; i++) {
        nd[i] = n[i]*1.0;
        diff_up[i] = sum_exact-sum_up[i];
        printf("%-11ld %17.16g %17.16g\n",n[i],sum_up[i],sum_exact-sum_up[i]);
    }
    
    for (int i = 0; i<N_max; i++) {
        diff_down[i] = sum_exact-sum_down[i];
        printf("%-11ld %17.16g %17.16g\n",n[i],sum_down[i],sum_exact-sum_down[i]);
    }
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("The program took %f seconds to execute\n", time_taken);
    
    
    /* gplot_twosetsline_loglog(nd,diff_up,N_max,nd,diff_down,N_max,
            "Summation Ordering Example","N","Difference From Exact Value",
            "Sum Up","Sum Down","Unix"); */
    gplot_twosetsline_loglog(nd,diff_up,N_max,nd,cpu_time_used,N_max,
            "Summation Ordering Example","N","Difference From Exact Value / CPU Time Taken (s)",
            "Sum Up","CPU Time","Unix");
    
    printf("Using double: \n");
    
    long billion = 1000000000;
    double big = 1.0;
    double small = 1e-9;
    double expected = 2.0;

    double sum = big;
    for (long i = 0; i < billion; ++i) {
        sum += small;
    }
    
    printf ("%g + %ld * %g = %17.16g difference = (%17.16g) \n",big,billion,small,sum,fabs(expected-sum));
 
    sum = 0;
    for (long i = 0; i < billion; ++i) {
        sum += small;
    }
    sum += big;
    
    printf ("%g * %ld  + %1g = %17.16g difference = (%17.16g) \n",big,billion,small,sum,fabs(expected-sum));
    
    printf("Using float: \n");
    
    long billionf = 1000000000;
    float bigf = 1.0;
    float smallf = 1e-9;
    float expectedf = 2.0;

    float sumf = bigf;
    for (long i = 0; i < billion; ++i) {
        sumf += smallf;
    }
    
    printf ("%g + %ld * %g = %17.16g difference = (%17.16g) \n",bigf,billionf,smallf,sumf,fabs(expectedf-sumf));
 
    sumf = 0;
    for (long i = 0; i < billion; ++i) {
        sumf += smallf;
    }
    sumf += bigf;
    
    printf ("%g * %ld  + %1g = %17.16g difference = (%17.16g) \n",bigf,billionf,smallf,sumf,fabs(expectedf-sumf));

    return (EXIT_SUCCESS);
    
}

