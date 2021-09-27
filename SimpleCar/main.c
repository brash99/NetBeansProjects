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
   
   myCar = Drive(milesForward,myCar);
   myCar = Reverse(milesReverse,myCar);
   HonkHorn(myCar);   
   Report(myCar);
  
   return (EXIT_SUCCESS);
   
}

