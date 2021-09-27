/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

#include <stdio.h>
#include <string.h>

#include "PointerCar.h"

PointerCar InitCar(){
   
   PointerCar newCar;
 
   newCar.miles = 0;
   
   printf("In InitCar: address of newCar = %p\n",&newCar);
   
   return newCar;
   
}

void Drive(int dist, PointerCar* car){
   car->miles = car->miles + dist;
   printf("In Drive: address of car = %p\n",car);
   return;
}
 
void Reverse(int dist, PointerCar* car){
   car->miles = car->miles - dist;
   printf("In Reverse: address of car = %p\n",car);
   return;
}
   
int GetOdometer(PointerCar* car){
   return car->miles;
}

void HonkHorn(PointerCar* car){
   printf("In HonkHorn: address of car = %p\n",car);
   printf("beep beep\n");
   return;
}

void Report(PointerCar* car){
   printf("In Report: address of car = %p\n",car);
   printf("Car has driven: %d miles\n", car->miles);
   return;
}
