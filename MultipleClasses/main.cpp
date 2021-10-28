/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 28, 2021, 12:57 PM
 */

#include <cstdlib>
#include "Metric.h"
#include "Imperial.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Metric::BiggerUnit();

    Imperial::SmallerUnit();
    
    Metric::SmallerUnit();

    Imperial::BiggerUnit();

    return 0;
}

