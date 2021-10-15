/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   Calculator.h
 * Author: brash
 *
 * Created on October 14, 2021, 8:33 PM
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Calculator_struct {
   double value;
} Calculator;

Calculator InitCalculator();
Calculator Add(double add, Calculator calc);
Calculator Subtract(double sub, Calculator calc);
Calculator Multiply(double factor, Calculator calc);
Calculator Divide(double factor, Calculator calc);
Calculator Clear(Calculator calc);
double GetValue(Calculator calc);



#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H */

