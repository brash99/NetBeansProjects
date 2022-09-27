/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

#include <stdio.h>
#include <string.h>

#include "PointerCar.h"

// Initializer method ... same as in SimpleCar!
PointerCar InitCar(){
   
   PointerCar newCar;
   PointerCar* pNewCar;
 
   newCar.miles = 0;
   newCar.age = 0.0;
   strcpy(newCar.make, "Toyota");
   strcpy(newCar.model, "Camry");

   printf("In InitCar: address of newCar = %p\n",pNewCar);
   
   return newCar;
   
}

// Getter and Setter Methods

int GetOdometer(PointerCar* pCar) {
    printf("In GetOdometer: address of car = %p\n", pCar);
    return pCar->miles;
}

void SetOdometer(PointerCar* pCar, int mileage) {
    printf("In SetOdometer:  address of car = %p\n", pCar);
    pCar->miles = mileage;
    return;
}

double GetAge(PointerCar* pCar) {
    printf("In GetAge: address of car = %p\n", pCar);
    return pCar->age;
}

void SetAge(PointerCar* pCar, double age) {
    printf("In SetAge:  address of car = %p\n", pCar);
    pCar->age = age;
    return;
}

char* GetMake(PointerCar* pCar) {
    //static char localmake[20];
    //strcpy(localmake, car.make);
    printf("In GetMake: address of car = %p\n", pCar);
    return pCar->make;
}

void SetMake(PointerCar* pCar, char* make) {
    printf("In SetMake: address of car = %p\n", pCar);
    strcpy(pCar->make, make);
    printf("In SetMake: make = %s\n", pCar->make);
    return;
}

char* GetModel(PointerCar* pCar) {
    //static char localmodel[20];
    //strcpy(localmodel, car.model);
    printf("In GetModel: address of car = %p\n", pCar);
    return pCar->model;
}

void SetModel(PointerCar* pCar, char* model) {
    printf("In SetModel: address of car = %p\n", pCar);
    strcpy(pCar->model, model);
    printf("In SetModel: model = %s\n", pCar->model);;
    return;
}

// Complex Methods

void Drive(int dist, PointerCar* pCar) {
    printf("In Drive:  address of car = %p\n", pCar);
    int current = GetOdometer(pCar);
    SetOdometer(pCar, current + dist);
    printf("In Drive: address of car = %p\n", pCar);
    return;
}

void Reverse(int dist, PointerCar* pCar) {
    printf("In Reverse:  address of car = %p\n", pCar);
    int current = GetOdometer(pCar);
    SetOdometer(pCar, current - dist);
    printf("In Reverse: address of car = %p\n", pCar);
    return;
}

void HonkHorn(PointerCar* pCar) {
    printf("In HonkHorn: address of car = %p\n", pCar);
    printf("beep beep\n");
    return;
}

void Report(PointerCar* pCar) {
    printf("In Report: address of car = %p\n", pCar);

    printf("Make of Car: %s\n", GetMake(pCar));
    printf("Model of Car: %s\n", GetModel(pCar));
    printf("Age of Car: %lf\n", GetAge(pCar));
    printf("Car has driven: %d miles\n", GetOdometer(pCar));
    return;
}
