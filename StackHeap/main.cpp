/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on November 10, 2021, 7:41 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

int myGlobal = 33;

void myFunction() {
    int myLocal;
    myLocal = 999;
    cout << " " << myLocal;
    return;
}

int main(int argc, char** argv) {
    
    int myInt;
    int* myPtr = nullptr;
    
    myInt = 555;
    
    myPtr = new int;
    *myPtr = 222;
    
    cout << *myPtr << " " << myInt;
    
    delete myPtr;
    
    myFunction();
    
    return 0;
}

