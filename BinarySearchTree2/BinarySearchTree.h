/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BinarySearchTree.h
 * Author: 00465510
 *
 * Created on December 7, 2021, 10:22 PM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Element.h"
#include <string>

struct TreeNode {
  Element value;        // data field
  TreeNode* left;   // to hold the address of the left child
  TreeNode* right;  // to hold the address of the right child
};

class BinarySearchTree {
private:
  TreeNode* root_;              // Pointer to the root node
   
  void destroyAll(TreeNode* r); // private method to destroy the tree (in consort with destructor)
  void insert(Element, TreeNode* &r); // private method to insert a new element into the tree

  //additional private recursive functions to be added

  std::string InOrder(TreeNode* r) const; // private method to create a one-line string of all elements in tree in order
  int getHeight(TreeNode* r) const; // private method to retrieve current height of the tree
  void copyHelper(TreeNode* &thisRoot, TreeNode* sourceRoot); // private method to copy one (existing) tree into another new tree.
  bool search(Element key, TreeNode* r) const; // private helper method for searching tree for a value
  
public:
  // constructors and destructors
  BinarySearchTree(); // default constructor
  BinarySearchTree(const BinarySearchTree& source); // copy constructor
  
  ~BinarySearchTree(); // destructor              

  // Binary tree operations
  void insert(Element key); //public insert method
  void display() const; //public display method
  int height() const; //public method to get height of tree
  bool search(Element key) const; // public method to search tree for existence of a value
  BinarySearchTree& operator=(const BinarySearchTree &source); // public override of = operator
  
};

#endif /* BINARYSEARCHTREE_H */

