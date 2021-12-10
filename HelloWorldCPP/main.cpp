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
#include <cmath> //C math library functions
#include <string> // The string class

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

  // Adding a comment in replit
    
    cout << "Hello World!" << endl;
    
    int a=14657;
    float b = 0.54;
    double c = 4.5678902392;
    
    cout << endl;
    
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    
    cout << endl;
    
    cout << "c = " << setprecision(5) << c << endl;
    
    cout << "c = " << setprecision(9) << c << endl;
    
    cout << fixed;
    
    cout << endl;
    
    cout << "b = " << setprecision(5) << b << endl;
    
    cout << "b = " << setprecision(9) << b << endl;
    
    cout << scientific;
    
    cout << endl;
    
    cout << "c = " << setprecision(5) << c << endl;
    
    cout << "c = " << setprecision(9) << c << endl;
    
    cout << endl;
    
    int i,j;
    cout << "Enter a number:" << endl;
    cin >> i;
    cout << "Enter another number:" << endl;
    cin >> j;
    
    cout << "The numbers are " << i << " and " << j << endl;
    
    int k;
    double d = 2.0;
    double e = 2.5;
    k = static_cast<int>(d*e*e);
    
    cout << "The integer k is " << k << endl;
    
    cout << "The integer k^2 is " << pow(k,2) << endl;
    
    
    string s1,s2,s3;
    
    cout << "Enter a name on a single line" << endl;
    
    cin >> s1;
    cin >> s2;
    
    cout << "S1 = <" << s1 << ">" << endl;
    cout << "S2 = <" << s2 << ">" << endl;
    
    
    string sphrase;
    
    cout << "Enter a name on a single line: " << endl;
    
    cin.ignore();
    getline(cin,sphrase);
    
    cout << "Name = <" << sphrase << ">" << endl;
    

    return 0;
}

