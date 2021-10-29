/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:18 PM
 */

#include <cstdlib>
#include <iostream>
#include "Triangle.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Triangle triangle1;
    Triangle triangle2;

    // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
    double base1, height1;
    cin >> base1;
    cin >> height1;
    
    triangle1.SetBase(base1);
    triangle1.SetHeight(height1);
    
    // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
   
    double base2, height2;
    cin >> base2;
    cin >> height2;
    
    triangle2.SetBase(base2);
    triangle2.SetHeight(height2);
    
    // TODO: Determine larger triangle (use GetArea())      
    double area1 = triangle1.GetArea();
    double area2 = triangle2.GetArea();
    
    cout << "Triangle with larger area:" << endl;
    
    if (area1 > area2) {
        triangle1.PrintInfo();
    } else {
        triangle2.PrintInfo();
    }

    // TODO: Output larger triangle's info (use PrintInfo())
    
    return 0;
}

