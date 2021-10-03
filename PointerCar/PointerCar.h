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
} PointerCar;

PointerCar InitCar();
void Drive(int dist, PointerCar* car);
void Reverse(int dist, PointerCar* car);
int GetOdometer(PointerCar* car);
void HonkHorn(PointerCar* car);
void Report(PointerCar* car);


#ifdef __cplusplus
}
#endif

#endif /* POINTERCAR_H */

