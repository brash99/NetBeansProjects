/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   SimpleCar.h
 * Author: brash
 *
 * Created on October 14, 2021, 8:28 PM
 */

#ifndef SIMPLECAR_H
#define SIMPLECAR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SimpleCar_struct {
   int miles;
} SimpleCar;

SimpleCar InitCar();
SimpleCar Drive(int dist, SimpleCar car);
SimpleCar Reverse(int dist, SimpleCar car);
int GetOdometer(SimpleCar car);
void HonkHorn(SimpleCar car);
void Report(SimpleCar car);



#ifdef __cplusplus
}
#endif

#endif /* SIMPLECAR_H */

