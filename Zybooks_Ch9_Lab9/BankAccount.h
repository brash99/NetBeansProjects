/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   BankAccount.h
 * Author: brash
 *
 * Created on October 14, 2021, 8:35 PM
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

typedef struct BankAccount_struct {
   char name[20];
   double checking;
   double savings;
} BankAccount;

BankAccount InitBankAccount(char* name, double chkamt, double savamt);
BankAccount SetName(char* name, BankAccount acct);
void GetName(char* name, BankAccount acct);
BankAccount SetChecking(double amount, BankAccount acct);
double GetChecking(BankAccount acct);
BankAccount SetSavings(double amount, BankAccount acct);
double GetSavings(BankAccount acct);
BankAccount DepositChecking(double amount, BankAccount acct);
BankAccount DepositSavings(double amount, BankAccount acct);
BankAccount WithdrawChecking(double amount, BankAccount acct);
BankAccount WithdrawSavings(double amount, BankAccount acct);
BankAccount TransferToSavings(double amount, BankAccount acct);

#endif /* BANKACCOUNT_H */

