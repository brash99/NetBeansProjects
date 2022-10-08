/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 25, 2021, 11:14 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 6
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

void zylab1() {
    
   const unsigned int NUM_ELEMENTS = 20;         // Number of input integers
   int userVals[NUM_ELEMENTS];          // Array to hold the user's input integers

   int num;
   scanf("%d",&num);
   
   for (int i=0;i<num;i++) {
      scanf("%d",&userVals[i]);
   }
   
   for (int i=num-1;i>=0;i--) {
      printf("%d,",userVals[i]);
   }
   printf("\n");
   
}

void zylab2() {
    
   const unsigned int NUM_ELEMENTS = 9;
   int userValues[NUM_ELEMENTS];    // Set of data specified by the user

   int icount=0;
   int temp = 0;
   
   while (temp>=0) {
      scanf("%d",&temp);
      userValues[icount] = temp;
      icount++;
   }
   
   int idx=icount/2-1; // calculate the index of the "middle element"
                       // icount will be the number of elements in the array, PLUS ONE!!!
                       // Suppose that icount = (even number) = 6 (i.e. 5 elements in the array)
                       // Then, idx = icount/2-1 = 6/2 - 1 = 3 - 1 = 2
                       // The 5 elements in the array are indices 0,1,2,3,4, thus 2 is the middle
                        
   if (icount<=NUM_ELEMENTS+1) {
      printf("Middle item: %d\n",userValues[idx]);
   } else {
      printf("Too many numbers\n");
   }
    
}

void zylab3() {
   
   const int NUM_ELEMENTS = 20;
   int userVals[NUM_ELEMENTS];    // Set of data specified by the user

   int numElements;
   scanf("%d",&numElements);
   
   for (int i=0;i<numElements;i++) {
      scanf("%d",&userVals[i]);
   }
   
   int threshold;
   scanf("%d",&threshold);
   
   for (int i=0; i<numElements; i++) {
      if (userVals[i] <= threshold) {
         printf("%d,",userVals[i]);
      }
   }
   printf("\n");
 
}

void zylab4() {
   
   const int NUM_ELEMENTS = 20;
   double userVals[NUM_ELEMENTS];    // Set of data specified by the user

   int numElements;
   scanf("%d",&numElements);
   
   for (int i=0; i<numElements; i++) {
      scanf("%lf",&userVals[i]);
   }
   
   double max = 0.0;
   for (int i=0; i<numElements; i++) {
      if (userVals[i] > max) {
         max = userVals[i];
      }
   }
   
   //printf("max = %0.2f\n",max);
   
   for (int i=0; i<numElements; i++) {
      printf("%0.2f ",(userVals[i]/max));
   }
   
   printf("\n");
   
}


int main(int argc, char** argv) {

    printf("1. Zylab1\n2. Zylab2\n3. Zylab3\n4. Zylab4\n\n");
    printf("Enter the number of the Zylab to run: \n");
    
    int ichoice;
    scanf("%d",&ichoice);
    
    switch(ichoice) {
        
        case 1:
            printf("Calling Zylab1 ... \n");
            zylab1();
            break;
            
        case 2:
            printf("Calling Zylab2 ... \n");
            zylab2();
            break;
            
        case 3:
            printf("Calling Zylab3 ... \n");
            zylab3();
            break;
            
        case 4:
            printf("Calling Zylab4 ... \n");
            zylab4();
            break;
            
    }
    return (EXIT_SUCCESS);
}

