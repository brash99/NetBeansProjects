/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

#include <stdio.h>
#include <string.h>

#include "VendingMachine.h"

VendingMachine InitVendingMachine(){
   VendingMachine newVM;
   
   newVM.bottles = 20;
   
   return newVM;
}

VendingMachine Purchase(int amount, VendingMachine vm){
   vm.bottles = vm.bottles - amount;  
   
   return vm;
}

VendingMachine Restock(int amount, VendingMachine vm){
   vm.bottles = vm.bottles + amount;
   
   return vm;
}

int GetInventory(VendingMachine vm){
   return vm.bottles;
}

void Report(VendingMachine vm){
   printf("Inventory: %d bottles\n", vm.bottles);
}