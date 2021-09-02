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

// Another useful pre-processor directive is the #define directive
#define THE_ANSWER 42 // numerical constants
#define REALTYPE double // variable types - makes it easy to switch between
                        // double and float, for example.

/* Let's also include math.h, which is a header file which defines:
 a) mathematical constants, using #define statements
 b) function prototypes, such as sqrt, sin, cos, etc. */

#include <math.h>

/* The way that C works is that when one uses the #include pre-processor
 * directive, the specified header file actually gets 'included' in the C
 * code prior to compilation.  
 * 
 * These header files just contain the *definitions* of the methods/functions:
 * what kind of variable(s) the function returns, and the format of the
 * arguments to the functions.  One can think of these header files as a
 * sort of API for the functions in the library.
 * 
 * The actual *code* for the functions is contained
 * in a separate (binary) library file that is linked with the object file(s)
 * for user code at linking time.
 * 
 * It works the same way for user-defined packages/libraries.  One can include
 * the header file for the user library, and then link to the (binary) user 
 * library at linking time.
 */

/* C also allows composite data types ... extremely useful! 
 
 We will define it here, before any of our functions, so that
 they all will know what it means
 
 BTW, it is this struct composite data type that is at the heart of all
 object oriented programming!!! We will see this again in C++ 
 
 Very simply, in our example, cartesianVector is a class with three (public)
 member fields (x,y, and z).  Later in the code, we will instantiate objects
 of this class.
 
 */  

struct cartesianVector {
    double x;
    double y;
    double z;
};

/* Define a function to calculate the length of a vector in 3D 
 Notice that it uses the previously defined struct, as well as
 some functions from the math library.  */

double length(struct cartesianVector r) {
    double len = sqrt(pow(r.x,2) + pow(r.y,2) + pow(r.z,2));
    return len;
}

/*
 * Main function ... the use of (int argc, char** argv) allows us
 * to pass arguments from the command line. More on this later!
 */

int main(int argc, char** argv) {
    
    /* C is strongly typed - all variables must be declared, by type */
    double x;
    double y;
    int i,j;
   
    /* In C, variables are NOT initialized ... need to be careful!!! */
    double z = 1.0;
    double t = 2.0, w = 3.0;
    double a, b;
    a=b=0.0;
    
    printf("Uninitialized variables: x = %g, y = %g, i,j = %d,%d \n",x,y,i,j);
    printf("Initialized variables: z,t,w,a,b = %g,%g,%g,%g,%g \n\n",z,t,w,a,b);
    
    /* A MAJOR bug source in C can occur when performing calculations with
     variables of mixed type ... be careful!!!!!!!! */
    
    i = 5;
    j = 10;
    double ratio = i/j;
    
    printf("Ratio of %d to %d is %g\n",i,j,ratio);
    printf("Yikes!\n\n");
    
    /* The solution here is to temporarily "type-cast" (haha!) a variable 
     * from one type to another within an expression ... we usually just say
     * that we "cast" the variable
     * 
     * Note that only one of the integers needs to be cast to a double to make
     * the entire right hand side be of type double */
    
    ratio = i/(double)j;
    
    printf("Ratio of %d to %d is %g\n",i,j,ratio);
    printf("Phew!\n\n");
    
    int n1, n2;
    n1 = 73;
    n2 = 56;
     
    printf("\nNumbers Before Exchange");
    printf("\n----------------------------\n");
    printf("n1 = %d and n2 = %d\n", n1, n2);

    /* Swap Variables Using Bitwise Operator */
    /* ^ is the "exclusive OR" operator */

    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
    
    /* Why does this work?
     * 73 = 101001 in binary
     * 56 = 111000 in binary
     * n1 = n1 ^ n2 = (101001)xor(111000) = 010001
     * n2 = n1 ^ n2 = (010001)xor(111000) = 101001 = 73 in base 10
     * n1 = n1 ^ n2 = (010001)xor(101001) = 111000 = 56 in base 10
     * 
     * BUT!!!!!  Only works for integer representations
     * 
     */
     
    printf("\nNumbers After Exchange");
    printf("\n----------------------------\n");
    printf("n1 = %d and n2 = %d\n\n", n1, n2);
    
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
    
    double mydouble = 123.456;
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
    
    mydouble = 1.23456E-02;
    printf ("------------\n");
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
