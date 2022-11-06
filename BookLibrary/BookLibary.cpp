/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "BookLibary.h"
#include <iostream>

Book::Book() {
   bookTitle = "";
   bookAuthor = "";
   bookISBN = 0;
}

Book::Book(string userBookTitle, string userBookAuthor, long userBookISBN) {
   bookTitle = userBookTitle;
   bookAuthor = userBookAuthor;
   bookISBN = userBookISBN;
}

long Book::GetBookISBN() const{
   return bookISBN;
}
string Book::GetBookTitle() const{
   return bookTitle;
}
string Book::GetBookAuthor() const{
   return bookAuthor;
}

void Book::PrintInfo() const{
   cout << "Title: " << bookTitle << endl;
   cout << "Author: " << bookAuthor << endl;
   cout << "ISBN: " << bookISBN << endl;
}

BookNode::BookNode() {
   bookTitle = "";
   bookAuthor = "";
   bookISBN = 0;
   nextNodePtr = nullptr;
}

// Constructor
BookNode::BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit) {
   bookTitle = bookTitleInit;
   bookAuthor = bookAuthorInit;
   bookISBN = bookISBNInit;
   nextNodePtr = nullptr;
}

// Constructor
BookNode::BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit, BookNode* nextLoc) {
   bookTitle = bookTitleInit;
   bookAuthor = bookAuthorInit;
   bookISBN = bookISBNInit;
   nextNodePtr = nextLoc;
}
// insertAfter
void BookNode::insertAfter(BookNode* nodeLoc){
   BookNode* tmpNext;

   tmpNext = nextNodePtr;
   nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

// setNext
void BookNode::SetNext(BookNode* nodeLoc) {
   nextNodePtr = nodeLoc;
}

// Get location pointed by nextNodePtr
BookNode* BookNode::GetNext() const{
   return nextNodePtr;
}

long BookNode::GetBookISBN() const{
   return bookISBN;
}

// Print book information
void BookNode::PrintBookInfo() const{
   cout << "Title: " << bookTitle << endl;
   cout << "Author: " << bookAuthor << endl;
   cout << "ISBN: " << bookISBN << endl;
}

LinkedListLibrary::LinkedListLibrary() {
   // Front of nodes list
   headNode = nullptr;
   lastNode = nullptr;
}

LinkedListLibrary::~LinkedListLibrary() {
   while(headNode != nullptr) {
      BookNode* tempNode = headNode->GetNext();
      delete headNode;
      headNode = tempNode;
   }
}

int LinkedListLibrary::InsertSorted(BookNode* newNode, int counter) {
   BookNode* currNode, nextNode;

   // Special case for head node
   if (headNode == nullptr || headNode->GetBookISBN() >= newNode->GetBookISBN()) {
      newNode->SetNext(headNode);
      headNode = newNode;
   }
   else {
      // Locate the node before insertion point
      currNode = headNode;

      while (currNode->GetNext() && currNode->GetNext()->GetBookISBN() < newNode->GetBookISBN()) {
         currNode = currNode->GetNext();
      }
      currNode->insertAfter(newNode);
   }

   ++counter;
   return counter;
}

void LinkedListLibrary::PrintLibrary() const {
   BookNode* currNode;
   
   headNode->PrintBookInfo();
   cout << endl;

   currNode = headNode->GetNext();
   while (currNode != nullptr) {
      currNode->PrintBookInfo();
      cout << endl;
      currNode = currNode->GetNext();
   }
}

VectorLibrary::VectorLibrary() {
      vector<Book> library;
}

/*int VectorLibrary::InsertSorted(const Book &newBook, int counter) {
   Book currBook;

   // Add an empty element at end of list
   Book emptyBook;
   library.push_back(emptyBook);

   // Loop through elements starting at the end
   for (int i = library.size() - 2; i >=0; --i) {
      currBook = library.at(i);

      // If the current book's ISBN is larger than newBook's ISBN, shift
      // the current book down 1, count shift operation
      if(currBook.GetBookISBN() > newBook.GetBookISBN()){
         library.at(i + 1) = currBook;
         ++counter;
      }

      // Otherwise, place newBook at the next location (empty slot),
      // count insert operation
      else {
         library.at(i + 1) = newBook;
         ++counter;
         return counter;
      }
   }

   // If we get to the top of the list, place newBook on top
   library.at(0) = newBook;
   ++counter;
   return counter;
}*/


// Replacement for Zybook's InsertSorted Function
int VectorLibrary::InsertSorted(const Book &newBook, int counter) {
    
    for (int i = library.size()-1; i>=0; --i) {
        if (newBook.GetBookISBN()<library.at(i).GetBookISBN()) {
            library.insert(library.begin()+i,newBook);
            ++counter;
            return counter;
        }
    }
    
    // if we get to here, the library is empty, so we should just add the new book.
    library.push_back(newBook);
    ++counter;
    return counter;
}

void VectorLibrary::PrintLibrary() const {
   for (size_t i = 0; i < library.size(); ++i) {
      library.at(i).PrintInfo();
      cout << endl;
   }
}


