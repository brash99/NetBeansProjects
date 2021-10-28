/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Imperial.h
 * Author: 00465510
 *
 * Created on October 28, 2021, 12:58 PM
 */

#ifndef IMPERIAL_H
#define IMPERIAL_H

#include <iostream>

using namespace std;

namespace Imperial {
   int foot = 1;
   int inch = 12;
   float yard = 0.333;
        
   void SmallerUnit() {
      cout << "1ft = " << inch << "in" << endl;
   }

   void BiggerUnit() {
      cout << "1ft = " << yard << "yd" << endl;
   }
}

#endif /* IMPERIAL_H */

