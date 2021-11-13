/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "MileageTrackerNode.h"
#include <iostream>

// Constructor
MileageTrackerNode::MileageTrackerNode() {
   miles = 0.0;
   date = "";
   nextNodeRef = nullptr;
}

// Destructor
MileageTrackerNode::~MileageTrackerNode() {
   if(nextNodeRef != nullptr) {
      delete nextNodeRef;
   }
}

// Constructor
MileageTrackerNode::MileageTrackerNode(double milesInit, string dateInit) {
   miles = milesInit;
   date = dateInit;
   nextNodeRef = nullptr;
}

// Constructor
MileageTrackerNode::MileageTrackerNode(double milesInit, string dateInit, MileageTrackerNode* nextLoc) {
   miles = milesInit;
   date = dateInit;
   nextNodeRef = nextLoc;
}

/* Insert node after this node.
Before: this -- next
After:  this -- node -- next
*/
void MileageTrackerNode::InsertAfter(MileageTrackerNode* nodeLoc) {
   MileageTrackerNode* tmpNext;

   tmpNext = nextNodeRef;
   nextNodeRef = nodeLoc;
   nodeLoc->nextNodeRef = tmpNext;
}

// Get location pointed by nextNodeRef
MileageTrackerNode* MileageTrackerNode::GetNext() {
   return nextNodeRef;
}

void MileageTrackerNode::PrintNodeData(){
   cout << miles << ", " << date << endl;
}

