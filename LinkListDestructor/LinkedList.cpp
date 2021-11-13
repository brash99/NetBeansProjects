/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "LinkedList.h"
#include "IntNode.h"

LinkedList::LinkedList() {
   
   head = nullptr;
   cout << "In LinkedList constructor: " << head << endl;
}

LinkedList::~LinkedList() {
   cout << "In LinkedList destructor: " << endl;
    
   // The destructor deletes each node in the linked list
   while (head) {
      IntNode* next = head->GetNext();
      delete head;
      head = next;
   }
}

void LinkedList::Prepend(int dataValue) {
   IntNode* newNode = new IntNode(dataValue);
   newNode->SetNext(head);
   head = newNode;
}

IntNode* LinkedList::GetHead() const {
    return this->head;
}

void LinkedList::SetHead(IntNode* headPtr) {
    this->head = headPtr;
}

