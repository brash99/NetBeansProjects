/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on December 7, 2021, 10:21 PM
 */

#include <iostream>

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    
  BinarySearchTree original;
  
  int size = 8;
  Element test_case[10] = {44, 34, 18, 51, 17, 20, 12, 40};
  
  for (int i = 0; i < size; i++) {
    original.insert(test_case[i]);
    cout << "After adding " << test_case[i] << ", the tree has ";
    original.display();
    cout << "\nThe height of the tree is " << original.height() << endl;
  }

  cout << "\nReady to make a copy.\n";
  BinarySearchTree bstCopy(original);
  cout << "After copying, the copy has ";
  bstCopy.display();
  original.insert(100);
  bstCopy.insert(10);
  cout << "\nAfter adding 100 to the original: ";
  original.display();
  cout << "\nAfter adding 10 to the copy: ";
  bstCopy.display();

  cout << "\n\nReady to reset the copy to the original via =\n";
  bstCopy = original;
  cout << "\nThe copy now has ";
  bstCopy.display();
  cout << "\nNo change to the original: ";
  original.display();
  original.insert(60);
  cout << "\nAfter adding 60 to the original: ";
  original.display();
  bstCopy.insert(30);
  cout << "\nAfter adding 30 to the copy: ";
  bstCopy.display();
  
  cout << "\n\nNow let's search for things in the copy ... " << endl;
  
  bool myvar = bstCopy.search(0);
  cout << "\n\nSearching for 0 ... " << myvar << endl;
  
  myvar = bstCopy.search(17);
  cout << "Searching for 17 ... " << myvar << endl;
  
  myvar = bstCopy.search(51);
  cout << "Searching for 51 ... " << myvar << endl;
  
  myvar = bstCopy.search(68);
  cout << "Searching for 68 ... " << myvar << endl;

  cout << "\n\nEnd of the program, getting ready for the destructor\n\n";
  
  return 0;
}

