/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 1, 2021, 7:07 AM
 */

#include <stdio.h>
#include <stdlib.h>

/* Let's also include math.h, which is a header file which defines:
 a) mathematical constants, using #define statements
 b) function prototypes, such as sqrt, sin, cos, etc. */
#include <math.h>

/* C also allows composite data types ... extremely useful! 
 We will define it here, before any of our functions, so that
 they all will know what it means*/    
struct cartesianVector {
    double x;
    double y;
    double z;
};

/* Define a function to calculate the length of a vector in 3D 
 Notice that it uses the previously define struct, as well as
 some functions from the math library.  */
double length(struct cartesianVector r) {
    double len = sqrt(pow(r.x,2) + pow(r.y,2) + pow(r.z,2));
    return len;
}

/*
 * Main function ... the use of (int argc, char** argv) allows us
 * to pass arguments from the commmand line. More on this later!
 */
int main(int argc, char** argv) {
    
    /* C is strongly typed - all variables must be declared, by type */
    double x;
    double y;
   
    /* In C, variables are NOT initialized ... need to be careful!!! */
    double z = 1.0;
    double t = 2.0, w = 3.0;
    double a, b;
    a=b=0.0;
    
    /* Define a Cartesian vector "object", and initialize its components. */   
    struct cartesianVector v;
    v.x = 1.0; v.y = 2.0; v.z = 3.0;
    printf ("X = %g, Y = %g, Z = %g \n",v.x,v.y,v.z);
    
    /* Calculate the length of our vector, using the length() function defined
     above! */
    double vectorLength = length(v);
    printf ("Length of this vector = %g \n",vectorLength);
    
    /* Print formatting ... there is a LOT of detail here!! 
     
     The basic format codes are:
     
       d or i for an integer
􏰀       u for an unsigned integer
􏰀       c for a character
􏰀       s for a string
􏰀       f for a double, printed in fixed point format
􏰀       e for a double, printed in floating point format 􏰀 
       g for a double, using f or e whichever is better 􏰀 
       % for printing a %
     
     Between the % and the conversion character you can place:
􏰀           - a minus sign, specifying adjustment to the left
􏰀           - a plus sign, specifying that the sign of positive numbers 
                        should also be printed
􏰀           - a space, specifying that a space should be printed 
                        for the sign of positive numbers
     
    Followed by
􏰀           - a number that specifies the minimum field width
􏰀           - a period followed by a second number, specifying the
􏰀                    - maximum number of characters printed from a string
􏰀                    - maximum amount of decimals for a floating-point value
􏰀                    - minimum number of digits for an integer

     */
    
    char mystring[] = "PCSE";
    printf ("\n");
    printf ("This department is called %s.\n",mystring);
    
    double mydouble = 134.056;
    printf ("The number is %g\n",mydouble);
    printf ("The number is %7.3f\n",mydouble);
    printf ("The number is %7.3e\n",mydouble);
    printf ("The number is %7.5e\n",mydouble);
    printf ("The number is %7.1f\n",mydouble);
    printf ("The number is %-7.1f\n",mydouble);
    printf ("The number is %7.6f\n",mydouble);
    printf ("The number is %9.6f\n",mydouble);
    printf ("The number is %15.6f\n",mydouble);
    printf ("The number is %-15.6f\n",mydouble);
   
    return (EXIT_SUCCESS);
    
}
