/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   IntNode.h
 * Author: 00465510
 *
 * Created on November 6, 2021, 7:32 PM
 */

#ifndef INTNODE_H
#define INTNODE_H

#include <iostream>
using namespace std;

class IntNode {
    
public:
   IntNode(int dataValue); 
   ~IntNode();  // destructor
   
   int GetData() const;
   IntNode* GetNext() const;
   
   void SetData(int dataValue);
   void SetNext(IntNode* nextPtr);
    
private:
   int data;
   IntNode* next;
   
};



#endif /* INTNODE_H */

