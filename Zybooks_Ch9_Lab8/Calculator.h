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

// TODO: Define the Calculator_struct
typedef struct Calculator_struct {
   double value;
} Calculator;

// TODO: Declare functions
//       InitCalculator(), Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()
Calculator InitCalculator();
Calculator Add(double add, Calculator calc);
Calculator Subtract(double sub, Calculator calc);
Calculator Multiply(double factor, Calculator calc);
Calculator Divide(double factor, Calculator calc);
Calculator Clear(Calculator calc);
double GetValue(Calculator calc);


#endif /* CALCULATOR_H */

