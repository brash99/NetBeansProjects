/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 6, 2021, 7:32 PM
 */

#include <cstdlib>
#include "LinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // Create a linked list
   LinkedList* list = new LinkedList;
   for (int i = 1; i <= 5; ++i)
      list->Prepend(i * 10);
      
   // Free the linked list.
   // The LinkedList class destructor frees each node.
   delete list;

    return 0;
}

