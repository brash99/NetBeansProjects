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
    printf("The memory address of myLocal is %p\n",&myLocal);
    myLocal = 999;
    
    cout << " " << myLocal << endl;
    return;                               // Removes from Stack!!!!!
}

int main(int argc, char** argv) {
    
    printf("The memory address of myGlobal is %p\n",&myGlobal);
    
    int myInt;                            // The Stack
    printf("The memory address of myInt is %p\n",&myInt);
    
    int* myPtr = nullptr;                 // The Stack (for now)
    printf("The memory address of myPtr is %p\n",myPtr);
    
    myInt = 555;
    
    myPtr = new int;                      // The Heap
    printf("The memory address of myPtr is %p\n",myPtr);
    
    *myPtr = 222;
    
    cout << *myPtr << " " << myInt << endl;
    
    delete myPtr;                         // Removes from the Heap AND Stack
    
    myFunction();                         // Only myInt exists on Stack
    
    return 0;                             // Removes myInt from Stack
}

