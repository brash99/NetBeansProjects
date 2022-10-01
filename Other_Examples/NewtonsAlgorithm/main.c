/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 28, 2021, 4:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Program to calculate the roots of a function, given the function and its
 * derivative, using Newton's method 
 */

double f(double, double []);
double fp(double, double []);

int main(int argc, char** argv) {
    
    double a[4] = {1.0,-3.0,-1.0,3.0};
   
    double epsilon = 1.0E-8;
    double diff = 1.0E12;
    
    double x0 = 2.8;
    double xroot;
    
    while (diff > epsilon) {

        xroot = x0 - f(x0,a)/fp(x0,a);
        diff = xroot - x0;
        x0 = xroot;
        diff = fabs(diff);
        printf("%g ... %g\n",x0,diff);
    }
    
    printf("Root = %g\n",xroot);
    

    return (EXIT_SUCCESS);
}

double f(double x, double a[]) {
    return a[0]*pow(x,3)+a[1]*pow(x,2)+a[2]*x+a[3];
}

double fp(double x, double a[]) {
    return 3.0*a[0]*pow(x,2)+2.0*a[1]*x+a[2];
}

