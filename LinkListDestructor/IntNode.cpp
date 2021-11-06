/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "IntNode.h"

IntNode::IntNode(int dataValue) {
      cout << "In IntNode constructor (" << dataValue << ")" << endl;
      data = dataValue;
}

IntNode::~IntNode() {
      cout << "In IntNode destructor (";
      cout << data << ")" << endl;
}
