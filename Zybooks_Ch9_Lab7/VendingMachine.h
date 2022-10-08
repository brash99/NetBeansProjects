/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   VendingMachine.h
 * Author: brash
 *
 * Created on October 14, 2021, 8:31 PM
 */

#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct VendingMachine_struct {
   int bottles;
} VendingMachine;

VendingMachine InitVendingMachine();
VendingMachine Purchase(int amount, VendingMachine vm);
VendingMachine Restock(int amount, VendingMachine vm);
int GetInventory(VendingMachine vm);
void Report(VendingMachine vm);



#ifdef __cplusplus
}
#endif

#endif /* VENDINGMACHINE_H */

