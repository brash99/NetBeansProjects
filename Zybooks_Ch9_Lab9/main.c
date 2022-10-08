/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on October 14, 2021, 8:35 PM
 */

#include <stdio.h>
#include <string.h>

#include "BankAccount.h"

int main() {
   BankAccount account = InitBankAccount("Mickey", 500.00, 1000.00);
   char name[20];
   
   account = SetChecking(500, account);
   account = SetSavings(500, account);
   account = WithdrawSavings(100, account);
   account = WithdrawChecking(100, account);
   account = TransferToSavings(300, account);
   
   GetName(name, account);
   printf("%s\n", name);
   printf("$%.2f\n", GetChecking(account));
   printf("$%.2f\n", GetSavings(account));

   return 0;
}