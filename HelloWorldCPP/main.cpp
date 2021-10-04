/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 4, 2021, 5:42 AM
 */

#include <iostream> //cout, endl, fixed
#include <cstdlib>
#include <iomanip> //setprecision, setw

/*
 * 
 */
int main(int argc, char** argv) {
    
    std::cout << "Hello World!" << std::endl;
    
    int a=14657;
    float b = 0.54;
    double c = 4.5678902392;
    
    std::cout << std::endl;
    
    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "c = " << std::setprecision(5) << c << std::endl;
    
    std::cout << "c = " << std::setprecision(9) << c << std::endl;
    
    std::cout << std::fixed;
    
    std::cout << std::endl;
    
    std::cout << "b = " << std::setprecision(5) << b << std::endl;
    
    std::cout << "b = " << std::setprecision(9) << b << std::endl;
    
    std::cout << std::scientific;
    
    std::cout << std::endl;
    
    std::cout << "c = " << std::setprecision(5) << c << std::endl;
    
    std::cout << "c = " << std::setprecision(9) << c << std::endl;
    
    std::cout << std::endl;
    
    int i,j;
    std::cout << "Enter a number:" << std::endl;
    std::cin >> i;
    std::cout << "Enter another number:" << std::endl;
    std::cin >> j;
    
    std::cout << "The numbers are " << i << " and " << j << std::endl;

    return 0;
}

