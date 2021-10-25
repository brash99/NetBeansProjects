/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 17, 2021, 9:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <cassert> // Assert library for unit testing

using namespace std;

/*
 * 
 */

double HrMinToMin(int origHours, int origMinutes) {
    int totMinutes;
    
    totMinutes = static_cast<double>((origHours*60) + origMinutes);
    
    return totMinutes;
}

void testHrMinToMin(void) {
    cout << "Testing started ... " << endl;
    
    assert(HrMinToMin(0,0) == 0);
    assert(HrMinToMin(0,1) == 1);
    assert(HrMinToMin(0,99) == 99);
    assert(HrMinToMin(1,0) == 60);
    assert(HrMinToMin(5,0) == 300);
    assert(HrMinToMin(2,30) == 150);
    
    cout << "Testing completed." << endl; 
}


int main(int argc, char** argv) {
    
    testHrMinToMin();

    return 0;
}

