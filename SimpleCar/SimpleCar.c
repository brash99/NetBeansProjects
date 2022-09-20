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
   newCar.age = 0.0;
   strcpy(newCar.make,"Toyota");
   strcpy(newCar.model,"Camry");
   
   printf("In InitCar: address of newCar = %p\n",&newCar);
   
   return newCar;
}

// Getter and Setter Methods

int GetOdometer(SimpleCar car){
   return car.miles;
}

SimpleCar SetOdometer(SimpleCar car, int mileage){
   printf("In SetOdometer:  address of car = %p\n",&car);
   car.miles = mileage;
   return car;
}

double GetAge(SimpleCar car){
   return car.age;
}

SimpleCar SetAge(SimpleCar car, double age){
   car.age = age;
   return car;
}

char* GetMake(SimpleCar car){
   return car.make;
}

SimpleCar SetMake(SimpleCar car, char* make){
    char localmake[strlen(make)+1];
    strcpy(localmake,make);
    strcpy(car.make,localmake);
    printf("In SetMake: make = %s\n",car.make);
    return car;
}

char* GetModel(SimpleCar car){
   return car.model;
}

SimpleCar SetModel(SimpleCar car, char* model){
    char localmodel[strlen(model)+1];
    strcpy(localmodel,model);
    strcpy(car.model,localmodel);
    printf("In SetModel: model = %s\n",car.model);
    return car;
}

// Complex Methods

SimpleCar Drive(int dist, SimpleCar car){
   printf("In Drive:  address of car = %p\n",&car);
   //car.miles = car.miles + dist;
   car = SetOdometer(car,car.miles+dist);
   printf("In Drive: address of car = %p\n",&car);
   return car;
}
 
SimpleCar Reverse(int dist, SimpleCar car){
   printf("In Reverse:  address of car = %p\n",&car);
   //car.miles = car.miles - dist;
   car = SetOdometer(car,car.miles-dist);
   printf("In Reverse: address of car = %p\n",&car);
   return car;
}
   
void HonkHorn(SimpleCar car){
   printf("In HonkHorn: address of car = %p\n",&car);
   printf("beep beep\n");
}

void Report(SimpleCar car){
   printf("In Report: address of car = %p\n",&car);
   printf("Car has driven: %d miles\n", GetOdometer(car));
}
