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

int myGlobal = 33;                        // Static Memory

void myFunction() {
    int myLocal;                          // The Stack
    myLocal = 999;
    cout << " " << myLocal;
    return;                               // Removes from Stack!!!!!
}

int main(int argc, char** argv) {
    
    int myInt;                            // The Stack
    int* myPtr = nullptr;                 // The Stack (for now)    
    myInt = 555;
    
    myPtr = new int;                      // The Heap
    *myPtr = 222;
    
    cout << *myPtr << " " << myInt;
    
    delete myPtr;                         // Removes from the Heap AND Stack
    
    myFunction();                         // Only myInt exists on Stack
    
    return 0;                             // Removes myInt from Stack
}

