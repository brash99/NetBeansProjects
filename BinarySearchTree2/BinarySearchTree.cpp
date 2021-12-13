/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

// Default constructor sets an empty tree
BinarySearchTree::BinarySearchTree()
{
    this->root_= nullptr;
}

bool BinarySearchTree::search(Element key) const {
    return !(this->search(key,this->root_));
}

bool BinarySearchTree::search(Element key, TreeNode* r) const {
    
    bool result = true;
    
    if (r == nullptr) {
        return true;
    }
    
    if (r->value == key) {
        return false;
    }
    
    result = result*search(key,r->left);
    result = result*search(key,r->right);
    
    return result;
    
}


//the public insert method                  
void BinarySearchTree::insert(Element key)
{
    //Call the private recursive insert method
    this->insert(key, this->root_);
}

//the private recursive insert method.
void BinarySearchTree::insert(Element key, TreeNode* &r)
{
    if (r == nullptr) {
        cout << "nullptr" << endl;
    } else {
        cout << r->value << " " << r->left << " " << r->right << endl;
    }
    
    if (r == nullptr) {
        cout << "creating new node for " << key << endl;
        r = new TreeNode{key, nullptr, nullptr};         
    }    else if (r->value < key) {
        cout << "calling insert again for right ... " << key << " " << r->right << endl;
        insert(key, r->right);
    }    else if (r->value > key)    {
        cout << "calling insert again for left  ... " << key << " " << r->left << endl;
        insert(key, r->left);
    }
}

//recursively release all nodes in the tree
void BinarySearchTree::destroyAll(TreeNode* r)
{
  if (r == nullptr) {
    //base case
    return;
  }

  //recursive case
  destroyAll(r->left);
  destroyAll(r->right);
  cout << r->value << " ";
  delete r;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
  //TBD
    //cout << "In public copy constructor " << bst.root_->value << endl;
    if (source.root_ == nullptr) {
        this->root_ = nullptr;
    } else {
        copyHelper(this->root_, source.root_);
    }
    
}

void BinarySearchTree::copyHelper(TreeNode* &thisRoot, TreeNode* sourceRoot) {
    
    if (sourceRoot == nullptr) {
        //cout << "Setting null pointer " << endl;
        thisRoot = nullptr;
    } else {
        //cout << "In private copy helper " << sourceRoot->value << endl;
        thisRoot = new TreeNode;
        thisRoot->value = sourceRoot->value;
        //cout << "Value at this point = " << sourceRoot->value << endl;
        //cout << "Calling left ... " << sourceRoot->left << endl;
        copyHelper(thisRoot->left, sourceRoot->left);
        //cout << "Calling right ... " << endl;
        copyHelper(thisRoot->right, sourceRoot->right);
    }
    
}

//The destructor calls a private recursive destroyAll function to release all nodes in the tree
BinarySearchTree::~BinarySearchTree ()
{
  destroyAll(this->root_);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& source){
  //TBD
    
    //cout << "In public = override method " << bst.root_->value << endl;
    if (source.root_ == nullptr) {
        this->root_ = nullptr;
    } else {
        copyHelper(this->root_, source.root_);
    }
    
  return *this;
}

string BinarySearchTree::InOrder(TreeNode* r) const
{
  std::string s = "";
  if (!r) {
    return s;
  }
  s = s + InOrder(r->left);
  s = s + to_string(r->value) + " ";
  s = s + InOrder(r->right);
  return s;
}

//the public display method.  
void BinarySearchTree::display() const
{
    cout << InOrder(this->root_);
}

int BinarySearchTree::getHeight(TreeNode* r) const
{
   if (!r) {
     return 0;
   }
   else
   {
     int leftDepth = getHeight(r->left);
     int rightDepth = getHeight(r->right);

     if (leftDepth>rightDepth) {
       return (leftDepth+1);
     } else {
       return (rightDepth+1);
     }
   }
}

//the public height method.  
int BinarySearchTree::height() const
{
    int h = getHeight(this->root_);
    
    return h;
}


