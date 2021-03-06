/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BookLibaryAll.h
 * Author: 00465510
 *
 * Created on November 19, 2021, 2:04 PM
 */

#ifndef BOOKLIBARYALL_H
#define BOOKLIBARYALL_H

#include <string>
#include <vector>

using namespace std;

class Book{
   public:
      Book();

      Book(string userBookTitle, string userBookAuthor, long userBookISBN);

      long long GetBookISBN() const;

      void PrintInfo() const;
   
   private:
      string bookTitle;
      string bookAuthor;
      long long bookISBN;
};

class BookNode {
   public:
      BookNode();

      // Constructor
      BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit);

      // Constructor
      BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit, BookNode* nextLoc);

      // inserAfter
      void insertAfter(BookNode* nodeLoc);
      
      //setNext
      void SetNext(BookNode* nodeLoc);

      // Get location pointed by nextNodePtr
      BookNode* GetNext() const;

      long long GetBookISBN() const;

      // Print book information
      void PrintBookInfo() const;
   
   private:
      string bookTitle;
      string bookAuthor;
      long long bookISBN;
      BookNode* nextNodePtr; // Reference to the next node
};

class LinkedListLibrary {
   public:
      //Linked list nodes
      BookNode* headNode;
      BookNode* lastNode;

      LinkedListLibrary();

      ~LinkedListLibrary();

      int InsertSorted(BookNode* newNode, int counter);

      void PrintLibrary() const;
};

class VectorLibrary {
   public:
      VectorLibrary();

      int InsertSorted(const Book &newBook, int counter);

      void PrintLibrary() const;
   
   private:
   // vector library
   vector<Book> library;

};

#endif /* BOOKLIBARYALL_H */

