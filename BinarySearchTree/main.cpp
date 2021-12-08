/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on December 7, 2021, 8:14 PM
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
class BST
{
    int data;
    BST *left, *right;
 
public:
    // Default constructor.
    BST();
 
    // Parameterized constructor.
    BST(int);
 
    // Insert function.
    BST* Insert(BST*, int);
 
    // Inorder traversal.
    string Inorder(BST*);
    
    int maxDepth(BST*);
    
    int GetData() {return data;}
   
    
};
 
// Default Constructor definition.
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
 
// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

 
// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
 
// Inorder traversal function.
// This gives data in sorted order.
string BST ::Inorder(BST* root)
{
    string s = "";
    if (!root) {
        return s;
    }
    s = s + Inorder(root->left);
    s = s + to_string(root->data) + " ";
    s = s + Inorder(root->right);
    
    return s;
}

int BST ::maxDepth(BST* root)
{
    if (root == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    } 
}

// Driver code
int main()
{
    
    vector<int> elements;
    elements.push_back(44);
    elements.push_back(34);
    elements.push_back(18);
    elements.push_back(51);
    elements.push_back(17);
    elements.push_back(20);
    elements.push_back(12);
    elements.push_back(40);
    
    
    BST b, *root = NULL;
    root = b.Insert(root, elements[0]);
    cout << "After adding " << elements[0] << ", the tree has " << b.Inorder(root) << endl;
    cout << "The height of the tree is " << b.maxDepth(root) << endl;
    
    for (unsigned int i = 1; i<elements.size(); i++) {
        b.Insert(root,elements[i]);
        cout << "After adding " << elements[i] << ", the tree has " << b.Inorder(root) << endl;
        cout << "The height of the tree is " << b.maxDepth(root) << endl;
    }
    
    //b.Inorder(root);
    return 0;
}
