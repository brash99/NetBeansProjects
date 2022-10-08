/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on October 14, 2021, 8:30 PM
 */


#include <stdio.h>

#include "VendingMachine.h"

int main() {

   int drinksToBuy;
   int bottlesToStock;
   VendingMachine drinkMachine = InitVendingMachine();
      
   scanf("%d", &drinksToBuy);
   scanf("%d", &bottlesToStock);
   drinkMachine = Purchase(drinksToBuy, drinkMachine);
   drinkMachine = Restock(bottlesToStock, drinkMachine);
   Report(drinkMachine);

   return 0;
}