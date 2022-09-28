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
#include <math.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 2
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

void zylab1() {
    
   int userNum;
   int x;
   
   scanf("%d", &userNum);
   scanf("%d", &x);
   
   userNum = userNum / x;
   printf("%d", userNum);
   
   userNum = userNum / x;
   printf(" %d", userNum);
   
   userNum = userNum / x;
   printf(" %d", userNum);
   
   printf("\n");

}

void zylab2() {

   double ageYears;
   double weightPounds;
   double heartBPM; // beats per minute
   double timeMinutes;
   double calories;
   
   scanf("%lf", &ageYears);
   scanf("%lf", &weightPounds);
   scanf("%lf", &heartBPM);
   scanf("%lf", &timeMinutes);
   
   calories = ((ageYears * 0.2757) + (weightPounds * 0.03295) + (heartBPM * 1.0781) - 75.4991) * timeMinutes / 8.368;
                 
   printf("Calories: %0.2lf calories\n", calories); 

}

void zylab3() {
 
   double x;
   double y;
   double z;

   scanf("%lf", &x);
   scanf("%lf", &y);
   scanf("%lf", &z);
   
   printf("%0.2lf ", pow(x, z));
   printf("%0.2lf ", pow(x, pow(y, 2)));
   printf("%0.2lf ", fabs(y));
   printf("%0.2lf\n", sqrt(pow(x * y, z)));
   
}

void zylab4() {
    
   int userNum1;
   int userNum2;
   int userNum3;
   int userNum4;

   scanf("%d", &userNum1);
   scanf("%d", &userNum2);
   scanf("%d", &userNum3);
   scanf("%d", &userNum4);
   
   // Statistics using integer arithmetic (part 1)
   printf("%d", userNum1 * userNum2 * userNum3 * userNum4);
   printf(" %d\n", (userNum1 + userNum2 + userNum3 + userNum4) / 4);   
   
   // Statistics using floating-point arithmetic (part 2)
   printf("%0.3lf", (double)userNum1 * userNum2 * userNum3 * userNum4);
   printf(" %0.3lf\n", (userNum1 + userNum2 + userNum3 + userNum4) / 4.0);   // The .0 causes floating-point division
   
}

void zylab5() {
    
   char userName[50];
   
   scanf("%s", userName);
   printf("Hello %s, and welcome to CS Online!\n", userName);

}

void zylab6() {
    
   double dollars;
   int quarters;
   int dimes;
   int nickels;
   int pennies;

   scanf("%d", &quarters);
   scanf("%d", &dimes);
   scanf("%d", &nickels);
   scanf("%d", &pennies);
   dollars = (quarters*25 + dimes*10 + nickels*5 + pennies) / 100.0;
   printf("Amount: $%0.2lf\n", dollars);
    
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

