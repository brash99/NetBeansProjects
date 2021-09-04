/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 4, 2021, 10:03 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * This is program that solves the five Zylabs that are part of chapter 2
 * 
 * There is a single main function (as required in C) that calls six
 * functions (which each return void) corresponding to the six Zylabs
 * 
 */

void zylab1() {
   
   // The following code should be place inside the main() and return 0
   // statements in the zylab
    
   int userNum;
   int x;

   scanf("%d",&userNum);
   scanf("%d",&x);
   
   userNum=userNum/x;
   printf("%d ",userNum);
   userNum=userNum/x;
   printf("%d ",userNum);
   userNum=userNum/x;
   printf("%d\n",userNum);

}

void zylab2() {
    
   double age;
   double weight;
   double heartRate;
   double timeMinutes;
   double calories;

   scanf("%lf %lf %lf %lf", &age, &weight, &heartRate, &timeMinutes);

   calories = (age * 0.2757 + weight * 0.03295 + (heartRate * 1.0781) - 75.4991) * timeMinutes / 8.368;

   printf("Calories: %0.2lf calories\n", calories);
    
}

void zylab3() {
    
   double x;
   double y;
   double z;
   
   scanf("%lf %lf %lf", &x, &y, &z);
   double xpz, xpy2, yabs, srxypz;
   
   xpz = pow(x,z);
   xpy2 = pow(x,pow(y,2));
   yabs = fabs(y);
   srxypz = sqrt(pow(x*y,z));
   
   printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", xpz,xpy2,yabs,srxypz);
   
}

void zylab4() {
    
   int userNum1;
   int userNum2;
   int userNum3;
   int userNum4;
   
   scanf("%d",&userNum1);
   scanf("%d",&userNum2);
   scanf("%d",&userNum3);
   scanf("%d",&userNum4);
   
   int productInt;
   int averageInt;
   
   productInt = (userNum1*userNum2*userNum3*userNum4);
   averageInt = (userNum1+userNum2+userNum3+userNum4)/4;
   
   printf("%d %d\n",productInt,averageInt);
   
   double product;
   double average;
   
   product = ((double)userNum1*userNum2*userNum3*userNum4);
   average = (double)(userNum1+userNum2+userNum3+userNum4)/4.0;
   
   printf("%0.3lf %0.3lf\n",product,average);
    
}

void zylab5() {
    
   char userName[50];
   
   scanf("%s", userName);
   printf("Hello %s, and welcome to CS Online!\n", userName);

}

void zylab6() {
    
    double dollars;
    
    unsigned int pennies, nickels, dimes, quarters;
    scanf("%d %d %d %d",&quarters,&dimes,&nickels,&pennies);
    
    dollars = quarters*0.25+dimes*0.10+nickels*0.05+pennies*0.01;

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

    return (EXIT_SUCCESS);
}

