/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */


#include <stdio.h>
#include <string.h>

#include "SimpleCar.h"

SimpleCar InitCar(){
   SimpleCar newCar;
   
   newCar.miles = 0;
   
   printf("In InitCar: address of newCar = %p\n",&newCar);
   
   return newCar;
}

SimpleCar Drive(int dist, SimpleCar car){
   printf("In Drive:  address of car = %p\n",&car);
   car.miles = car.miles + dist;
   printf("In Drive: address of car = %p\n",&car);
   return car;
}
 
SimpleCar Reverse(int dist, SimpleCar car){
   printf("In Reverse:  address of car = %p\n",&car);
   car.miles = car.miles - dist;
   printf("In Reverse: address of car = %p\n",&car);
   return car;
}
   
int GetOdometer(SimpleCar car){
   return car.miles;
}

void HonkHorn(SimpleCar car){
   printf("In HonkHorn: address of car = %p\n",&car);
   printf("beep beep\n");
}

void Report(SimpleCar car){
   printf("In Report: address of car = %p\n",&car);
   printf("Car has driven: %d miles\n", car.miles);
}
