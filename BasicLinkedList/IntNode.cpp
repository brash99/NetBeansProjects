/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iomanip>
#include "IntNode.h"

// Constructor
IntNode::IntNode(int dataInit, IntNode* nextLoc) {
   this->dataVal = dataInit;
   this->nextNodePtr = nextLoc;
   
   cout << "Constructor: (" << dataInit << " : " << nextLoc << ")" << endl;
   
}

/* Insert node after this node.
 * Before: this -- next
 * After:  this -- node -- next
 */
void IntNode::InsertAfter(IntNode* nodeLoc) {
   IntNode* tmpNext = nullptr;
   
   tmpNext = this->nextNodePtr;    // Remember next
   this->nextNodePtr = nodeLoc;    // this -- node -- ?
   nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
   
   cout << "Insert After ... This (" << this->dataVal << " : " << this->nextNodePtr << ")" << endl;
}

// Print dataVal
void IntNode::PrintNodeData() {
    
    cout << "Node: "  << &(this->dataVal) << endl;
    cout << "---------------------" << endl;
    cout << "|" << setw(12) << this->dataVal << "       |" << endl;
    cout << "---------------------" << endl;
    cout << "|  " << setw(14) << this->nextNodePtr << "   |" << endl;
    cout << "---------------------" << endl;
    cout << "          |          " << endl;
    cout << "         \\_/         " << endl;
    
}

// Grab location pointed by nextNodePtr
IntNode* IntNode::GetNext() {
   return this->nextNodePtr;
}


