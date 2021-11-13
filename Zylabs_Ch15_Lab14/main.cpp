/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 12, 2021, 1:48 PM
 */


#include "MileageTrackerNode.h"
#include <string>
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
   // References for MileageTrackerNode objects
   MileageTrackerNode* headNode;
   MileageTrackerNode* currNode;
   MileageTrackerNode* lastNode;

   double miles;
   string date;
   int i;

   // Front of nodes list
   headNode = new MileageTrackerNode();
   lastNode = headNode;

   // TODO: Read in the number of nodes
   int n_nodes;
   cin >> n_nodes;
   cin.ignore();
   
   // TODO: For the read in number of nodes, read
   //       in data and insert into the linked list
   
   for (int i=0; i<n_nodes; i++) {
      cin >> miles;
      cin.ignore();
      getline(cin, date);
      currNode = new MileageTrackerNode(miles, date);
      lastNode->InsertAfter(currNode);
      lastNode = currNode;
   }
      
   // TODO: Call the PrintNodeData() method
   //       to print the entire linked list

   currNode = headNode->GetNext();
   while (currNode != nullptr) {
      currNode->PrintNodeData();
      currNode = currNode->GetNext();
   }

   // MileageTrackerNode Destructor deletes all
   //       following nodes
   delete headNode;
}