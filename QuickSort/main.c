/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 *
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 7, 2021, 9:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_double(const void *ap, const void *bp) {
    
    /* printf("First pointer is: %p\n",ap);
    printf("Second pointer is: %p\n",bp); */
    
    const double *a = (const double *) ap;
    const double *b = (const double *) bp;
    
    /* printf("First value is: %g\n",*a);
    printf("Second value is: %g\n",*b); */
    
    if (*a < *b) {
        return -1;
    }
    
    if (*a == *b) {
        return 0;
    }
    
    if (*a > *b ) {
        return 1;
    }

    return -2;
    
}

/*
 * Example of using the qsort() function in stdlib to sort
 * an array
 * 
 */
int main(int argc, char** argv) {
    
    double a[] = {3.0,1.5,2.0,6.0,9.6,3.14159265};
    
    printf("Original array is:\n"); 
    for (int i=0;i<6;i++) {
        printf("a[%i]=%e\n",i,a[i]); 
    }
    printf ("\n");
    
    /* The qsort function takes four arguments:
     1. the array to be sorted
     2. the number of elements in that array
     3. the number of bytes in each elements of the array
     4. the NAME of a function, that the user writes, which 
     compares elements of the array - the function needs to return
     -1 if the first element is less than the second, 0 if they are equal
     and 1 if the first element is greater than the second */
    
    qsort(a,6,sizeof(double),compare_double);
    
    printf("Sorted array is:\n"); 
    for (int i=0;i<6;i++) {
        printf("a[%i]=%e\n",i,a[i]); 
    }
    printf ("\n");

    return (EXIT_SUCCESS);
}

