/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   IntNode.h
 * Author: 00465510
 *
 * Created on November 5, 2021, 11:00 PM
 */

#include <iostream>

using namespace std;

#ifndef INTNODE_H
#define INTNODE_H

class IntNode {
public:
   IntNode(int dataInit = 0, IntNode* nextLoc = nullptr); // constructor
   ~IntNode(); // destructor
   
   void InsertAfter(IntNode* nodeLoc);
   void RemoveAfter();
   
   IntNode* GetNext();
   void PrintNodeData();
private:
   int dataVal;
   IntNode* nextNodePtr;
};

#endif /* INTNODE_H */

