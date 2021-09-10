/*
 * Program to investigate the effects of numerical precision, rounding error,
 * etc. on the calculation of the derivative of a function.
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 30, 2021, 11:57 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gplot.h>

#define REALTYPE double

/* Define a function, of type REALTYPE, that will take the x-value and return
 the value of the function at that x-value */
REALTYPE function(REALTYPE xval) {
    return xval*xval*xval;
}

/* Define a derivative function, of type REALTYPE, that will take the 
 * x-value and return the derivative of the function at that x-value */
REALTYPE deriv(REALTYPE xval) {
    return 3.0*xval*xval;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    /* Define the number of h-values where we will test the 
     * numerical precision */
    const int N_max = 20;
    
    /* Define some arrays to hold the values of h, f, fprime (both exact and
     * numerical), and the difference between exacts and numerical */
    REALTYPE h[N_max], f[N_max], fprime_exact[N_max], 
            fprime_numerical[N_max],diff[N_max];
    
    /* Define the x-value where we will evaluate the function 
     * and its derivative */
    REALTYPE x0 = 1.0;
    REALTYPE fval = function(x0);
    REALTYPE fprimeval = deriv(x0);
    
    printf("At x = %g, the exact value of the function f(x) = %g ... exact value of the derivative f'(x) = %g\n\n",x0,fval,fprimeval);
    
    for (int i=0; i<N_max; i++) {
        int power = -20+i;
        h[i] = pow(10,power);
        f[i] = function(x0);
        fprime_exact[i] = deriv(x0);
        fprime_numerical[i] = (function(x0+h[i]) - function(x0))/h[i];
        diff[i] = fabs(fprime_exact[i]-fprime_numerical[i]);
        printf("%5g %2.1f %2.1f %12.10f %12.10f\n",h[i],f[i],
                fprime_exact[i],fprime_numerical[i],diff[i]);
    }
    
    
    // Plot the results
    gplot_basicline_loglog(h,diff,N_max,"Numerical Calculation of Derivative",
            "h","Difference","My Data","Unix");
    
    return (EXIT_SUCCESS);
}

