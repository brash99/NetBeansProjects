/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "IntNode.h"

IntNode::IntNode(int dataValue) {
      cout << "In IntNode constructor (" << dataValue << "," << next << ")" << endl;
      data = dataValue;
      next = nullptr;
}

IntNode::~IntNode() {
      cout << "In IntNode destructor (";
      cout << data << "," << next << ")" << endl;      
}

int IntNode::GetData() const {
    return data;
}

IntNode* IntNode::GetNext() const {
    return next;
}

void IntNode::SetData(int dataValue) {
    this->data = dataValue;
}

void IntNode::SetNext(IntNode* nextPtr) {
    this->next = nextPtr;
}
