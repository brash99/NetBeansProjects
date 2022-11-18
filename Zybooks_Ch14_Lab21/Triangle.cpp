/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void Triangle::SetBase(double userBase) {
   base = userBase;
}

void Triangle::SetHeight(double userHeight) {
   height = userHeight;
}

double Triangle::GetArea() const {
   return 0.5 * base * height;
}

void Triangle::PrintInfo() const {
   cout << fixed << setprecision(2);
   cout << "Base: " << base << endl;
   cout << "Height: " << height << endl;
   cout << "Area: " << round(GetArea() * 100.0f) / 100.0f << endl;
}