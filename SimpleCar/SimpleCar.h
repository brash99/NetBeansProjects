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

SimpleCar InitCar();

// Getter and Setter Methods

int GetOdometer(SimpleCar car);
SimpleCar SetOdometer(SimpleCar car, int mileage);
double GetAge(SimpleCar car);
SimpleCar SetAge(SimpleCar car, double age);
char* GetMake(SimpleCar car);
SimpleCar SetMake(SimpleCar car, char* make);
char* GetModel(SimpleCar car);
SimpleCar SetModel(SimpleCar car, char* model);

// Complex Methods

SimpleCar Drive(int dist, SimpleCar car);
SimpleCar Reverse(int dist, SimpleCar car);
void HonkHorn(SimpleCar car);
void Report(SimpleCar car);

#endif /* SIMPLECAR_H */

