/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 26, 2021, 10:37 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "SimpleCar.h"

int main() {

   // The strategy in the main program should be that we ONLY call
   // the methods specified in SimpleCar.h!!  We don't manipulate the
   // internal variables of the struct directly ... this way, if we
   // decided to update/change/edit/evolve the internal structure
   // of SimpleCar objects, it will be largely transparent to the user.
   // 
   // The user should be able to look at an API for SimpleCar,
   // which details the SimpleCar methods, and figure out
   // how to write the code!
    
   // -------------------------------------------------------------
   
   // Get information from the user - number of miles to drive forward,
   // and the number of miles to drive in reverse.
   //
   int milesForward, milesReverse;
   printf("Miles forward = ");
   scanf("%d", &milesForward);
   printf("\n");
   printf("Miles reverse = ");
   scanf("%d", &milesReverse);
   printf("\n");
   
   // Initialize a new SimpleCar struct, called myCar
   SimpleCar myCar = InitCar();
   printf("In main 1:  address of myCar = %p\n",&myCar);
   printf("Mileage = %d\n",GetOdometer(myCar));
   
   // Drive forward by a specified amount
   myCar = Drive(milesForward,myCar);
   printf("In main 2:  address of myCar = %p\n",&myCar);
   printf("Mileage = %d\n",GetOdometer(myCar));
   
   // Drive in reverse by a specified amount
   myCar = Reverse(milesReverse,myCar);
   printf("In main 3:  address of myCar = %p\n",&myCar);
   printf("Mileage = %d\n",GetOdometer(myCar));
   
   // Change the make, model, and age of the car
        
   myCar = SetMake(myCar,"Mercedes-Benz");
   myCar = SetModel(myCar,"E350");
   myCar = SetAge(myCar,16.0);
   
   // Call the HonkHorn and Report methods
   HonkHorn(myCar);   
   Report(myCar);
  
   return (EXIT_SUCCESS);
   
}

