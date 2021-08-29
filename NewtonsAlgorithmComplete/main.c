/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 28, 2021, 7:11 PM
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
int found_root_yet(double, double [], int);

int main(int argc, char** argv) {
    
    double a[4] = {1.0,-3.0,-1.0,3.0};
    //double a[4] = {0.0,1.0,0.0,-4.0};
    
    // Set the upper lower limits for the search, and the number of divisions
    // of the interval
    double xmin = -4.0;
    double xmax = 4.0;
    
    // Choice of Npoints is important!!!
    //int Npoints = 10000;
    int Npoints = pow(2,13)-1;
    
    double dx = (xmax-xmin)/Npoints;
   
    // Set the tolerance for finding a root.
    double epsilon = 1.0E-8;
    
    // Main loop:
    
    double roots[3]={-10000.0,-10000.0,-10000.0};
    int nroots_found = 0;
    
    for (int i=0; i<Npoints; i++) {
        
        double diff = 1.0E12;
       
        double xroot;
        double x0 = xmin + i*dx;
        double previous_root;
        
        while (diff > epsilon) {
            
            xroot = x0 - f(x0,a)/fp(x0,a);
            diff = xroot - x0;
            x0 = xroot;
            diff = fabs(diff);
 
        }
        
        if (found_root_yet(xroot,roots,nroots_found) == 0 && nroots_found < 3) {
            roots[nroots_found] = xroot;
            nroots_found=nroots_found+1;
            printf("Found new root!!!!  root = %g\n",xroot);
        }
   
    }
    
    printf("nroots_found = %d\n",nroots_found);
    printf("Roots = %g , %g, %g\n",roots[0],roots[1],roots[2]);

    return (EXIT_SUCCESS);
}

double f(double x, double a[]) {
    return a[0]*pow(x,3)+a[1]*pow(x,2)+a[2]*x+a[3];
}

double fp(double x, double a[]) {
    return 3.0*a[0]*pow(x,2)+2.0*a[1]*x+a[2];
}

int found_root_yet(double xroot, double roots[], int nroots) {
    
    int found = 0;
    for (int i=0; i<nroots;i++) {
        if (fabs(xroot-roots[i])<0.000001) {
            found = 1;
        }
    }
    
    return found;
}

