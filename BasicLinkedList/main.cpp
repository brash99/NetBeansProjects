/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 5, 2021, 11:00 PM
 */

#include <iostream>
#include "IntNode.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
   IntNode* headObj  = nullptr; // Create IntNode objects (ON THE STACK)
   IntNode* nodeObj1 = nullptr;
   IntNode* nodeObj2 = nullptr;
   IntNode* nodeObj3 = nullptr;
   IntNode* nodeObj4 = nullptr;
   IntNode* nodeObj5 = nullptr;
   IntNode* currObj  = nullptr;
   
   cout << "headObj = " << &headObj << endl;
   cout << "nodeObj1 = " << &nodeObj1 << endl;
   cout << "nodeObj2 = " << &nodeObj2 << endl;
   cout << "nodeObj3 = " << &nodeObj3 << endl;
   cout << "nodeObj4 = " << &nodeObj4 << endl;
   cout << "nodeObj5 = " << &nodeObj5 << endl;
   cout << "currObj = " << &currObj << endl;
   
   // Front of nodes list
   headObj = new IntNode(-1); // Allocate on the HEAP!!!
   
   // Insert nodes
   nodeObj1 = new IntNode(111); // Allocate on the HEAP!!!
   headObj->InsertAfter(nodeObj1);
   
   nodeObj2 = new IntNode(222);
   nodeObj1->InsertAfter(nodeObj2);
   
   nodeObj3 = new IntNode(333);
   nodeObj2->InsertAfter(nodeObj3);
   
   nodeObj4 = new IntNode(444);
   nodeObj3->InsertAfter(nodeObj4);
   
   nodeObj5 = new IntNode(555);
   nodeObj4->InsertAfter(nodeObj5);
   
   // Print initial linked list
   currObj = headObj;
   cout << "Initial Linked List:" << endl;
   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }
   
   // Now, insert a new object in the middle of the list
   IntNode* nodeObj6 = nullptr;
   nodeObj6 = new IntNode(666);
   nodeObj2->InsertAfter(nodeObj6);
   
   // Print linked list
   currObj = headObj;
   cout << "Linked List after insertion:" << endl;
   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }
  
    return 0;
}

