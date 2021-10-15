/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

#include <stdio.h>
#include <string.h>

#include "BankAccount.h"

BankAccount InitBankAccount(char* name, double chkamt, double savamt) {
   BankAccount newAcct;
   strcpy(newAcct.name,name);
   newAcct.checking = chkamt;
   newAcct.savings = savamt;
   
   return newAcct;
}

BankAccount SetName(char* name, BankAccount acct) {
   strcpy(acct.name,name);
   return acct;
}

void GetName(char* name, BankAccount acct) {
   strcpy(name, acct.name);
}

BankAccount SetChecking(double amount, BankAccount acct) {
   acct.checking = amount;
   return acct;
}

double GetChecking(BankAccount acct){
   return acct.checking;
}

BankAccount SetSavings(double amount, BankAccount acct) {
   acct.savings = amount;
   return acct;
}

double GetSavings(BankAccount acct){
   return acct.savings;
}

BankAccount DepositChecking(double amount, BankAccount acct) {
   if (amount >= 0) {
      acct.checking = acct.checking + amount;
   }
   return acct;
}

BankAccount DepositSavings(double amount, BankAccount acct) {
   if (amount >= 0) {
      acct.savings = acct.savings + amount;
   }
   return acct; 
}
BankAccount WithdrawChecking(double amount, BankAccount acct) {
   if (amount >= 0) {
      acct.checking = acct.checking - amount;
   }
   return acct;
}

BankAccount WithdrawSavings(double amount, BankAccount acct) {
   if (amount >= 0) {
      acct.savings = acct.savings - amount;
   }
   return acct;
}

BankAccount TransferToSavings(double amount, BankAccount acct) {
   acct.savings = acct.savings + amount;
   acct.checking = acct.checking - amount;
   return acct;
}