/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Metric.h
 * Author: 00465510
 *
 * Created on October 28, 2021, 12:57 PM
 */

#ifndef METRIC_H
#define METRIC_H

#include <iostream>

using namespace std;

namespace Metric {
   int meter = 1;
   int millimeter = 1000;
   float kilometer = 0.001;
        
   void SmallerUnit() {
      cout << "1m = " << millimeter << "mm" << endl;
   }

   void BiggerUnit() {
      cout << "1m = " << kilometer << "km" << endl;
   }
}

#endif /* METRIC_H */

