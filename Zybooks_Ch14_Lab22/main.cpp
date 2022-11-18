 /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:28 PM
 */

#include <iostream>
#include "Car.h"
using namespace std;

int main(int argc, const char* argv[]) {
   int userYear;
   int userPrice;
   int userCurrentYear;
   Car myCar;
      
   cin >> userYear;
   cin >> userPrice;
   cin >> userCurrentYear;
      
   myCar.SetModelYear(userYear);
   myCar.SetPurchasePrice(userPrice);
   myCar.CalcCurrentValue(userCurrentYear);
      
   myCar.PrintInfo();
   
   return 0;
}

