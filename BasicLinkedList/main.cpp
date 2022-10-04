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
   
    cout << "Contruct some nodes:\n";
   IntNode* headObj  = new IntNode(1); // Create IntNode objects (On the Heap)
   IntNode* nodeObj1 = new IntNode(22);
   IntNode* nodeObj2 = new IntNode(333);
   IntNode* nodeObj3 = new IntNode(4444);
   IntNode* nodeObj4 = new IntNode(55555);
   IntNode* nodeObj5 = new IntNode(666666);
   IntNode* currObj  = nullptr;
   cout << endl;
   
   cout << "Where are these nodes actually located?\n";
   cout << "headObj => " << headObj << endl;
   cout << "nodeObj1 => " << nodeObj1 << endl;
   cout << "nodeObj2 => " << nodeObj2 << endl;
   cout << "nodeObj3 => " << nodeObj3 << endl;
   cout << "nodeObj4 => " << nodeObj4 << endl;
   cout << "nodeObj5 => " << nodeObj5 << endl;
   cout << "currObj => " << currObj << endl;
   cout << endl;
   
   
   // Insert nodes
   cout << "Now, let's create the linked list!\n";
   headObj->InsertAfter(nodeObj1);
   nodeObj1->InsertAfter(nodeObj2);
   nodeObj2->InsertAfter(nodeObj3);
   nodeObj3->InsertAfter(nodeObj4);
   nodeObj4->InsertAfter(nodeObj5);
   cout << endl;
   
   // Print initial linked list
   currObj = headObj;
   cout << "Initial Linked List:" << endl << endl;
   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }
   
   // Now, insert a new object in the middle of the list
   cout << endl;
   cout << "Create a new node, and insert it after nodeObj2\n";
   IntNode* nodeObj6 = new IntNode(7777777);
   nodeObj2->InsertAfter(nodeObj6);
   
   // Print linked list
   currObj = headObj;
   cout << endl;
   cout << "Linked List after insertion:" << endl;
   cout << endl;
   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }
   
   // Remove the second node
   headObj->RemoveAfter();
   
   // Print linked list
   currObj = headObj;
   cout << endl;
   cout << "Linked List after removal:" << endl;
   cout << endl;
   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }
  
    return 0;
}

