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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PointerCar_struct {
   int miles;
   double age;
   char make[20];
   char model[20];
} PointerCar;

PointerCar InitCar();

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


#ifdef __cplusplus
}
#endif

#endif /* POINTERCAR_H */

