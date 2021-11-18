/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   LinkedList.h
 * Author: 00465510
 *
 * Created on November 6, 2021, 7:36 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "IntNode.h"

#include <iostream>
using namespace std;

class LinkedList {
public:
    
   LinkedList();
   ~LinkedList();  //destructor frees up entire linked list
   
   void Prepend(int dataValue);
   
   IntNode* GetHead() const;
   void SetHead(IntNode* headPtr); 
   
private:
   IntNode* head;
   
};

#endif /* LINKEDLIST_H */

