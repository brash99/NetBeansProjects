/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 7, 2021, 7:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <gplot.h>
#include <math.h>

/*
 * Program to draw an Archimedean Spiral, based on parameters from the user
 */
 
#define pi M_PI
 
int main(){
    
	double a,b,cycles,incr,theta;
	double steps;
        double xcoord[20000],ycoord[20000];
 
	/* printf("Enter the parameters a and b : ");
	scanf("%lf%lf",&a,&b);
 
	printf("Enter cycles : ");
	scanf("%lf",&cycles);
 
	printf("Enter divisional steps : ");
	scanf("%lf",&steps); */
        
        a = 2.0;
        b = 0.2;
        cycles = 100.0;
        steps = 1.5;
 
	incr = 1.0/steps;
 
	//initwindow(1000,1000,"Archimedean Spiral");
 
        int idx=0;
	for(theta=0;theta<=cycles*pi;theta+=incr){

            xcoord[idx] = (a + b*theta)*cos(theta);
            ycoord[idx] = (a + b*theta)*sin(theta);
            
            printf("%g %g %g\n",theta,xcoord[idx],ycoord[idx]);
                        
            idx++;
	}
        
        //printf("%d %g %g\n",idx,xcoord[1570],ycoord[1570]);
        
        gplot_basicline(xcoord,ycoord,idx-1," "," "," "," ","Unix");
        system("/usr/local/bin/gnuplot -persistent /Users/brash/NetBeansProjects/ArchimedianSpiral/gnuplotScript");

    return (EXIT_SUCCESS);
}

