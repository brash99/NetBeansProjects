/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   SimpleCar.h
 * Author: brash
 *
 * Created on September 26, 2021, 10:38 PM
 */

#ifndef SIMPLECAR_H
#define SIMPLECAR_H

typedef struct SimpleCar_struct {
   int miles;
   double age;
   char make[20];
   char model[20];
} SimpleCar;

// Initializer
SimpleCar InitCar();

// Getter and Setter Methods
//
// In this version, the getter methods return an object of the type
// of the corresponding internal variable in the SimpleCar struct, and
// the setter methods return a complete (updated) SimpleCar struct.
//

int GetOdometer(SimpleCar car);
SimpleCar SetOdometer(SimpleCar car, int mileage);
double GetAge(SimpleCar car);
SimpleCar SetAge(SimpleCar car, double age);
char* GetMake(SimpleCar car);
SimpleCar SetMake(SimpleCar car, char* make);
char* GetModel(SimpleCar car);
SimpleCar SetModel(SimpleCar car, char* model);

// Complex Methods
// 
// In these methods, we will use ONLY the setter and getter methods
// to retrieve/update the SimpleCar object, and NOT access the internal
// variables of the struct directly.
//

SimpleCar Drive(int dist, SimpleCar car);
SimpleCar Reverse(int dist, SimpleCar car);
void HonkHorn(SimpleCar car);
void Report(SimpleCar car);

#endif /* SIMPLECAR_H */

