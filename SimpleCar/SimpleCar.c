/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */


#include <stdio.h>
#include <string.h>

#include "SimpleCar.h"

//  Initializer method
//  
//   create a SimpleCar struct, initialize the variables within that
//   struct, and the return the entire struct.
//
SimpleCar InitCar(){
   SimpleCar newCar;

   newCar.miles = 0;
   newCar.age = 0.0;
   strcpy(newCar.make, "Toyota");
   strcpy(newCar.model, "Camry");
   
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
   printf("In SetAge:  address of car = %p\n",&car);
   car.age = age;
   return car;
}

char* GetMake(SimpleCar car){
    static char localmake[20];
    strcpy(localmake,car.make);
    return localmake;
}

SimpleCar SetMake(SimpleCar car, char* make){
    strcpy(car.make,make);
    printf("In SetMake: make = %s\n",car.make);
    return car;
}

char* GetModel(SimpleCar car){
    static char localmodel[20];
    strcpy(localmodel,car.model);
    return localmodel;
}

SimpleCar SetModel(SimpleCar car, char* model){
    strcpy(car.model,model);
    printf("In SetModel: model = %s\n",car.model);
    return car;
}

// Complex Methods

SimpleCar Drive(int dist, SimpleCar car){
   printf("In Drive:  address of car = %p\n",&car);
   car = SetOdometer(car,GetOdometer(car)+dist);
   printf("In Drive: address of car = %p\n",&car);
   return car;
}
 
SimpleCar Reverse(int dist, SimpleCar car){
   printf("In Reverse:  address of car = %p\n",&car);
   car = SetOdometer(car,GetOdometer(car)-dist);
   printf("In Reverse: address of car = %p\n",&car);
   return car;
}
   
void HonkHorn(SimpleCar car){
   printf("In HonkHorn: address of car = %p\n",&car);
   printf("beep beep\n");
}

void Report(SimpleCar car){
   printf("In Report: address of car = %p\n",&car);
   
   printf("Make of Car: %s\n",GetMake(car));
   printf("Model of Car: %s\n",GetModel(car));
   printf("Age of Car: %lf\n",GetAge(car));
   printf("Car has driven: %d miles\n", GetOdometer(car));
}
