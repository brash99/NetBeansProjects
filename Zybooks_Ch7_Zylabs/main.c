/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 26, 2021, 2:30 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 7
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

double DrivingCost(double milesPerGallon, double dollarsPerGallon, double milesDriven) {
   return milesDriven/milesPerGallon*dollarsPerGallon;
}

void CoinFlip(char* decisionString) {
   int rnum = rand()%2;
   printf("%d\n",rnum);
   
   if (rnum==0) {
        strcpy(decisionString,"Tails");
   } else {
        strcpy(decisionString,"Heads");
   }
   return;
 } 

void SwapValues(int* userVal1, int* userVal2, int* userVal3, int* userVal4) {
   int temp = *userVal1;
   *userVal1 = *userVal2;
   *userVal2 = temp;
   temp = *userVal3;
   *userVal3 = *userVal4;
   *userVal4 = temp;
   
}

int Fibonacci(int n) {

   double phi = (sqrt(5.0)+1.0)/2.0;
   double f = (pow(phi,n)-pow(-1.0*phi,-1.0*n))/sqrt(5.0);
   //printf("%d %lf\n",n,f);
   
   if (n<0) {
      return -1;
   } else {
      return (int)f;
   }
}


void zylab1() {
    
   double milesPerGallon, dollarsPerGallon;

   scanf("%lf",&milesPerGallon);
   scanf("%lf",&dollarsPerGallon);
   
   printf("%0.2lf ",DrivingCost(milesPerGallon,dollarsPerGallon,10.0));
   printf("%0.2lf ",DrivingCost(milesPerGallon,dollarsPerGallon,50.0));
   printf("%0.2lf\n",DrivingCost(milesPerGallon,dollarsPerGallon,400.0));
   
   return;
    
}

void zylab2() {
   
   int a,b,c,d;
   
   scanf("%d",&a);
   scanf("%d",&b);
   scanf("%d",&c);
   scanf("%d",&d);
   
   SwapValues(&a,&b,&c,&d);
   
   printf("%d %d %d %d\n",a,b,c,d);
   
   return;
      
}

void zylab3() {
    
   int choice;
   scanf("%d",&choice);

   srand(2);  /* Unique seed */
   
   char output[5];

   for (int i=0; i<choice; i++) {
      CoinFlip(output);
      printf("%s\n",output);
   }

   return;
     
}

void zylab4() {
   
   int startNum;
   scanf("%d", &startNum);
   
   printf("Fibonacci(%d) is %d", startNum, Fibonacci(startNum));

   return;
   
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

