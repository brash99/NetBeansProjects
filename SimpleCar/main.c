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

   int milesForward, milesReverse;
   scanf("%d", &milesForward);
   scanf("%d", &milesReverse);
   
   SimpleCar myCar = InitCar();
   printf("In main 1:  address of myCar = %p\n",&myCar);
   
   myCar = Drive(milesForward,myCar);
   
   printf("In main 2:  address of myCar = %p\n",&myCar);
   
   myCar = Reverse(milesReverse,myCar);
   
   printf("In main 3:  address of myCar = %p\n",&myCar);
   
   HonkHorn(myCar);   
   Report(myCar);
  
   return (EXIT_SUCCESS);
   
}

