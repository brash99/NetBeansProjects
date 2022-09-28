/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 4, 2021, 11:35 AM
 */

#include <stdio.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 1
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

void zylab1() {
    
   int userNum;
   int userNumSquared;
   
   scanf("%d", &userNum);
   
   userNumSquared = userNum*userNum;   // Bug here; fix it when instructed
   
   printf("%d\n", userNumSquared); 

}

void zylab2() {

   int x;

   printf("Enter x: \n");
   scanf("%d", &x);
   
   // printf("%d\n", x);  // Student mistakenly is echoing the input to output to match example
   printf("x doubled is: %d\n", 2 * x);    

}

void zylab3() {
 
   printf("Hello World!\n");
   
}

void zylab4() {
    
   printf("  NO PARKING\n");
   printf("2:00 - 6:00 a.m.\n");
    
}

void zylab5() {
    
   int baseInt;
   int headInt;
   
   scanf("%d", &baseInt);
   scanf("%d", &headInt);
   
   printf("    %d\n", headInt);
   printf("    %d%d\n", headInt, headInt);
   printf("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
   printf("%d%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt, headInt);
   printf("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
   printf("    %d%d\n", headInt, headInt);
   printf("    %d\n", headInt);

}

void zylab6() {
    
   printf("Step 1 complete\n");
   printf("Step 2 as well\n");
   printf("All steps now complete\n");
    
}

int main(int argc, char** argv) {
    
    printf("1. Zylab1\n2. Zylab2\n3. Zylab3\n4. Zylab4\n5. Zylab5\n6. Zylab6\n\n");
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
               
        case 5:
            printf("Calling Zylab5 ... \n");
            zylab5();
            break;   
            
        case 6:
            printf("Calling Zylab6 ... \n");
            zylab6();
            break; 
                      
    }

    return 0;
}

