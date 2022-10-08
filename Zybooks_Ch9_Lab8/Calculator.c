/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

#include <stdio.h>
#include <string.h>

#include "Calculator.h"

// TODO: Define functions
//       InitCalculator(), Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()

Calculator InitCalculator() {
   Calculator newCalc;
   newCalc.value=0.0;
   return newCalc;
}

Calculator Add(double add, Calculator calc) {
   calc.value = calc.value + add;
   return calc;
}

Calculator Subtract(double sub, Calculator calc) {
   calc.value = calc.value - sub;
   return calc;
}

Calculator Divide(double factor, Calculator calc) {
   if (factor!=0) {
      calc.value=calc.value/factor;
      return calc;
   } else {
      printf("Divide by zero attempt!!!!!\n");
      return calc;
   }
}

Calculator Multiply(double factor, Calculator calc) {
      calc.value=calc.value*factor;
      return calc;
}

Calculator Clear(Calculator calc) {
   calc.value = 0;
   return calc;
}

double GetValue(Calculator calc) {
   return calc.value;
}
