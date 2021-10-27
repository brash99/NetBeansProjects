/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 25, 2021, 10:38 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Demonstration of some of the important aspects of operator overloading
 * 
 * Redefining/defining the meaning of +, -, and *
 *  
 */

#include "TimeHrMn.h"

int main(int argc, char** argv) {
    
    TimeHrMn time1(3, 22, 45.0);
    TimeHrMn time2(2, 50, 34.2);
    TimeHrMn sumTime;

    sumTime = time1 + time2;
    sumTime.Print();
    
    return 0;
}

