/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   PointerCar.h
 * Author: brash
 *
 * Created on September 27, 2021, 2:58 PM
 */

#ifndef POINTERCAR_H
#define POINTERCAR_H

typedef struct PointerCar_struct {
   int miles;
   double age;
   char make[20];
   char model[20];
} PointerCar;

PointerCar InitCar();

// If we compare to SimpleCar.h, there are two main differences:
//
//  1. We will pass POINTERS to structs, rather than the structs themselves
//  2. For the setter methods, they are now of type void ... this is because
//     we will be manipulating the actual structs inside these methods, and
//     not copies!!!!

int GetOdometer(PointerCar* pCar);
void SetOdometer(PointerCar* car, int mileage);
double GetAge(PointerCar* pCar);
void SetAge(PointerCar* pCar, double age);
char* GetMake(PointerCar* pCar);
void SetMake(PointerCar* pCar, char* make);
char* GetModel(PointerCar* pCar);
void SetModel(PointerCar* pCar, char* model);


void Drive(int dist, PointerCar* pCar);
void Reverse(int dist, PointerCar* pCar);
void HonkHorn(PointerCar* pCar);
void Report(PointerCar* pCar);


#endif /* POINTERCAR_H */

