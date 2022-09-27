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
#include <stdlib.h>
#include <math.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 4
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

void zylab1() {
    
   int num1;
   int num2;
   int num3;
   
   scanf("%d", &num1); 
   scanf("%d", &num2); 
   scanf("%d", &num3); 
   
   if ((num1 <= num2) && (num1 <= num3)) {    // num1 is smaller than both num2 and num3, so is smallest
      printf("%d\n", num1); 
   } else if ((num2 <= num1) && (num2 <= num3)) { // num2 is smaller than both num1 and num3, so is smallest
      printf("%d\n", num2); 
   } else { // Neither num1 nor num2 are smaller, so num3 must be smallest
      printf("%d\n", num3);
   } 

}

void zylab2() {
    
   int highwayNumber;
   
   scanf("%d", &highwayNumber); 
   
   if (highwayNumber%100 == 0) {
      printf("%d is not a valid interstate highway number.\n",highwayNumber);
   } else {
      
      if (highwayNumber < 100) {
         // primary
      
         if (highwayNumber % 2 == 0) {
            // even interstate
            printf("I-%d is primary, going east/west.\n",highwayNumber);
         } else {
            // odd interstate
            printf("I-%d is primary, going north/south.\n",highwayNumber);
         }
      
      } else {
         // auxiliary
      
         int primary = highwayNumber%100;
         if (primary % 2 == 0) {
            // even interstate
            printf("I-%d is auxiliary, serving I-%d, going east/west.\n",highwayNumber,primary);
         } else {
            // odd interstate
            printf("I-%d is auxiliary, serving I-%d, going north/south.\n",highwayNumber,primary);
         }
      
      }
   }

}

void zylab3() {
    
   int inputVal;
   int numDollars;
   int numQuarters;
   int numDimes;
   int numNickels;
   int numPennies;
   
   scanf("%d", &inputVal);
   
   if (inputVal <= 0) {
      printf("No change\n"); 
   } // Could return at this point
   
   numDollars = inputVal / 100;
   inputVal -= numDollars * 100;
   
   numQuarters = inputVal / 25;
   inputVal -= numQuarters * 25;
   
   numDimes = inputVal / 10;
   inputVal -= numDimes * 10;
   
   numNickels = inputVal / 5;
   inputVal -= numNickels * 5;
   
   numPennies = inputVal;
   
   
   if (numDollars > 0) {
      printf("%d", numDollars);
      if (numDollars == 1) {
         printf(" Dollar\n");
      }
      else {
         printf(" Dollars\n");
      }
   }
   
   if (numQuarters > 0) {
      printf("%d", numQuarters);
      if (numQuarters == 1) {
         printf(" Quarter\n");
      }
      else {
         printf(" Quarters\n");
      }
   }

   if (numDimes > 0) {
      printf("%d", numDimes);
      if (numDimes == 1) {
         printf(" Dime\n");
      }
      else {
         printf(" Dimes\n");
      }
   }
   
   if (numNickels > 0) {
      printf("%d", numNickels);
      if (numNickels == 1) {
         printf(" Nickel\n");
      }
      else {
         printf(" Nickels\n");
      }
   }
   
   if (numPennies > 0) {
      printf("%d", numPennies);
      if (numPennies == 1) {
         printf(" Penny\n");
      }
      else {
         printf(" Pennies\n");
      }
   }
   
}

void zylab4() {
    
   int inputYear;
   
   scanf("%d", &inputYear);

   if (inputYear%4 != 0) {
      printf("%d - not a leap year\n",inputYear);
   } else {
      if (inputYear%100 == 0) {
         if (inputYear%400 == 0) {
            printf("%d - leap year\n",inputYear);
         } else {
            printf("%d - not a leap year\n",inputYear);
         }
      } else {
         printf("%d - leap year\n",inputYear);
      }
   }
    
}

void zylab5() {
    
   int val1;
   int val2;
   int val3;
   int max;

   scanf("%d %d %d", &val1, &val2, &val3);

   // First assume val1 is the largest.
   max = val1;
   // Update max if val2 is larger.
   if (val2 > max) {
      max = val2;
   }
   // Update max if val3 is larger.
   if (val3 > max) {
      max = val3;
   }

   printf("%d\n", max);

}

int main(int argc, char** argv) {
    
    printf("1. Zylab1\n2. Zylab2\n3. Zylab3\n4. Zylab4\n5. Zylab5\n\n");
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
                      
    }

    return (EXIT_SUCCESS);
}

