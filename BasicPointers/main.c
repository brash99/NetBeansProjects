/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 1, 2021, 1:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void swap(int* p1, int* p2) {
    
    /* 
     * The purpose of this function is to swap/exchange the values
     * stored at the memory locations p1 and p2.
     * Remember, the arguments of this function are pointers to 
     * locations in memory 
     */
    
    
    /* 
     * Step 1: get the value that is stored at the memory location p1 and
     * store it in a temporary variable
     */ 
    
    int temp = *p1;
    
    /* 
     * Step 2: Take the value that is stored at memory location p2, and put
     * that value into memory location p1 
     */
    
    *p1 = *p2;
    
    /* 
     * Step3:  Take the temporary value, and store that at memory location p2 
     */
    *p2 = temp;
    
}

char getChar(char* someString, int n) {
    
    /* A function to return the n-th character of a string
     * Notice that we pass the string from the main program, but
     * the argument of the function is a pointer to that string, which is of course
     * a pointer to the first character in the character array.
     */
    
    char* pa = &someString[n-1];
    char thisChar = *pa;
    
    return thisChar;
    
}

char getChar2(char someString[], int n) {
    
    /* A function to return the n-th character of a string
     * Notice that we pass the string from the main program, and the
     * argument here is a char array, which makes sense.  So, in the local
     * function an entire copy of the char array is created locally.
     */
    
    char thisChar = someString[n-1];
    
    return thisChar;
    
}

void changeChar(char* someString, int n, char someChar) {
    
    char* pa = &someString[n-1];
    *pa = someChar;
    
}


int main(int argc, char** argv) {
    
    /* 
     * The ability to access and manipulate the actual memory locations in C
     * is what makes it (a) fast, and (b) powerful.  The way that we do that is
     * by using pointers - a variable which "points" to the actual location in 
     * memory! 
     */
    
    int x = 10, y = 20;
    printf("x = %d, y = %d\n",x,y);
    
    /*
     * In C, arguments of functions are just numbers or letters - they are just
     * VALUES that get sent to the function. 
     * 
     * The notation, &x , means "the hexadecinal numerical value 
     * of the MEMORY LOCATION where the variable x is stored" 
     * 
     * - this is called a pointer in C.  
     * 
     * So, in the function call below, we are
     * not passing the values stored in x and y, but rather the actual memory 
     * locations of x and y
     * 
     * Let's begin by printing out these memory locations (using the %p 
     * formatting code).
     */
    
    printf("location of x = %p, location of y = %p\n",&x,&y);
    
    /* Define two new variables, which are pointers - they hold memory
     * locations.  Set their initial values to the memory locations
     * corresponding to x and y, from above.
     * 
     * Then, call a function which takes the values of these POINTERS 
     * as arguments 
     */
    
    int* px = &x;
    int* py = &y;
  
    swap(px, py); /* the purpose of this function is to swap the values x, y */
    
    printf("x = %d, y = %d\n",x,y);
    
    /* Another simple example to reinforce the concepts */
    
    int i = 7; /* define an integer variable at set it equal to 7 */
    int* p = &i; /* define an integer pointer variable, and set it equal to
                  * the location of the integer variable, i */
    int val = *p; /* define an integer variable and set it equal to the value
                   * that is stored at the memory location, p, which is a
                   * pointer to the memory location of the integer variable, i */
    
    printf("i = %d, val = %d \n",i,val);
    
    
    /* 
     * And now, some examples with arrays!!!! 
     * 
     * The usage of pointers with arrays is where C really shines :)
     * 
     * Remember - "strings" in C are just arrays of characters ...
     */
    
    char a[] = "The quick brown fox";
    char b[] = "jumped over the lazy dog.";
    
    /* Define two pointers, which point to the first character of each string */
    char* pa = &a[0];
    char* pb = &b[0];
    
    printf ("%s %s\n",a,b); /* The original strings ... %s makes sense */
    printf ("%p %p\n",pa,pb); /* Pointers to the first character ... %p makes sense */
    printf ("%c %c\n",*pa,*pb); /* The value stored at the first character location ... %c makes sense  */
    
    /* Next example: Let's pass a string to a function! */
    
    int n = 8;
    
    /* Method 1: a function using pointers */
    char myChar = getChar(a,n); /* this function should return the n-th character of the string
                                 * Note that when we pass the STRING itself, we are passing an
                                 * array ... in reality, we are passing a pointer to the first
                                 * element in that array!!! */
    
    /* Method 2: a function which makes a local copy */
    char myChar2 = getChar2(a,n); /* this function should return the n-th character of the string
                                 * Note that when we pass the STRING itself, we are passing an
                                 * array ... in reality, we are passing a pointer to the first
                                 * element in that array!!! */
    
    printf("The %d-th character of '%s' is %c.\n",n,a,myChar);
    printf("The %d-th character of '%s' is %c.\n",n,a,myChar2);
    
    /* Next example:  Let's CHANGE the string in some way! */
    printf("The original string is '%s'.\n",a);
    changeChar(a,n,'X'); /* This function should change the n-th character of the string to the specified character */
    printf("The new string is      '%s'.\n",a);
            
    return (EXIT_SUCCESS);

}

