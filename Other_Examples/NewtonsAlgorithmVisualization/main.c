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
#include <time.h>
#include <gplot.h>

/*
 * Program to calculate the roots of a function, given the function and its
 * derivative, using Newton's method 
 */

double f(double, double []);
double fp(double, double []);
int found_root_yet(double, double [], int);

int main(int argc, char** argv) {
    
    clock_t start, end;
    
    double a[4] = {1.0,-3.0,-1.0,3.0};
    //double a[4] = {0.0,1.0,0.0,-4.0};
    
    // Set the upper lower limits for the search.
    double xmin = -4.0;
    double xmax = 4.0;
   
    // Set the tolerance for finding a root.
    double epsilon = 1.0E-10;
    
    double npts[1000];
    double cpu_time_used[1000];
    
    int counter = 0;
    
    for (int Npoints=1000; Npoints>=10; Npoints=Npoints-1) {
    //for (int j=13;j>=3;j--) {
    //    int Npoints = pow(2,j)-1;
        start = clock();
        
        double dx = (xmax-xmin)/Npoints;
        
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
                //printf("%g:  %g\n",x0,diff);
 
            }
        
            //printf ("%d: Root = %g\n",i,xroot);
        
            if (found_root_yet(xroot,roots,nroots_found) == 0 && nroots_found < 3) {
                roots[nroots_found] = xroot;
                nroots_found=nroots_found+1;
                //printf("Found new root!!!!  root = %g\n",xroot);
            }
   
        }
    
        printf("Npoints = %d, nroots_found = %d\n",Npoints, nroots_found);
        printf("Roots = %g , %g, %g\n",roots[0],roots[1],roots[2]);
        
        end = clock();
        cpu_time_used[counter] = ((double) (end-start))/CLOCKS_PER_SEC;
        npts[counter] = Npoints;
        counter++;
        
    }
    
    gplot_basicline(npts,cpu_time_used,counter,"Newtons Root Finding", 
        "Number of Interval Points", "Time (s)", "Data", "Unix");
    

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
        if (fabs(xroot-roots[i])<1.0E-10) {
            found = 1;
        }
    }
    
    return found;
}

