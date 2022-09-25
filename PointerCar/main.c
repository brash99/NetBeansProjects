/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 27, 2021, 2:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "PointerCar.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
   int milesForward, milesReverse;
   printf("Miles forward = ");
   scanf("%d", &milesForward);
   printf("\n");
   printf("Miles reverse = ");
   scanf("%d", &milesReverse);
   printf("\n");

   PointerCar myCar = InitCar();
   PointerCar* pCar = &myCar;
   
   printf("\n");
   printf("In main 1:  address of myCar = %p\n", pCar);
   printf("Mileage = %d\n", GetOdometer(pCar));
   printf("\n");

   Drive(milesForward, pCar);
   printf("\n");
   printf("In main 2:  address of myCar = %p\n", pCar);
   printf("Mileage = %d\n", GetOdometer(pCar));
   printf("\n");

   Reverse(milesReverse, pCar);
   printf("\n");
   printf("In main 3:  address of myCar = %p\n", pCar);
   printf("Mileage = %d\n", GetOdometer(pCar));
   printf("\n");

   SetMake(pCar, "Mercedes-Benz");
   SetModel(pCar, "E350");
   SetAge(pCar, 16.0);
   
   HonkHorn(pCar);   
   Report(pCar);

   return (EXIT_SUCCESS);
}

