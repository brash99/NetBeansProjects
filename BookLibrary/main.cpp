/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 11, 2021, 8:42 AM
 */

#include "BookLibary.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

static const unsigned int nelements = 10000;

static const char alpha[] =
"abcdefghijklmnopqrstuvwxyz";

static const char caps[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int stringLength = sizeof(alpha) - 1;
int capsLength = sizeof(caps) - 1;

char genRandom() { // Random lower case generator function.
    return alpha[rand() % stringLength];
}

char genCap() { // Random upper case generator function.
    return caps[rand() % capsLength];
}

Book genBook(long isbn) {
    
    Book tempBook;
    
    string book_author, book_title;
    
    string temp = "The";
    
    for (int j=0; j<4; j++) {
        temp += " ";
        temp += genCap();
        for (int i=0; i<6; i++) {
            temp += genRandom();
        }
    }
    
    book_title = temp;
    //cout << book_title << endl;
    
    temp = "";
    
    temp += genCap();
    for (int i=0; i<8; i++) {
        temp += genRandom();
    }
    temp += ", ";
    
    temp += genCap();
    for (int i=0; i<6; i++) {
        temp += genRandom();
    }
    
    book_author = temp;
    //cout << isbn << endl;
    //cout << book_author << endl;
    
    tempBook = Book(book_title,book_author,isbn);
    
    return tempBook;
    
}

void CreateRandomLibrary(LinkedListLibrary &linkedListLibrary, VectorLibrary &vectorLibrary) {
    
    long isbn = 9780400000000;
    BookNode* currNode;
    Book tempBook;
    
    int linkedListOperations = 0;
    int vectorOperations = 0;
    
    for (int i = 0; i<2*nelements; i++) {
        
        tempBook = genBook(isbn+i*4000);
        vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);
        
        currNode = new BookNode(tempBook.GetBookTitle(), tempBook.GetBookAuthor(),
                tempBook.GetBookISBN());
        linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);
        linkedListLibrary.lastNode = currNode;
        
    }
    
}

void FillLibraries(LinkedListLibrary &linkedListLibrary, VectorLibrary &vectorLibrary) {
   ifstream inputFS; // File input stream
   int linkedListOperations = 0;
   int vectorOperations = 0;

   BookNode* currNode;
   Book tempBook;

   string bookTitle;
   string bookAuthor;
   long bookISBN;

   // Try to open file
   inputFS.open("books.txt");

   while(getline(inputFS, bookTitle)) {
      inputFS >> bookISBN;
      inputFS.ignore(1, '\n');
      getline(inputFS, bookAuthor);

      // Insert into linked list
      currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
      linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);
      linkedListLibrary.lastNode = currNode;
      
      // Insert into vector
      tempBook = Book(bookTitle, bookAuthor, bookISBN);
      vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);
   }

   inputFS.close(); // close() may throw ios_base::failure if fails
}

int main (int argc, const char* argv[]) {
   int linkedListOperations = 0;
   int vectorOperations = 0;

   // Create libraries
   LinkedListLibrary linkedListLibrary = LinkedListLibrary();
   VectorLibrary vectorLibrary;
   
   // Create library file
   CreateRandomLibrary(linkedListLibrary, vectorLibrary);

   // Fill libraries with 100 books
   //FillLibraries(linkedListLibrary, vectorLibrary);

   // Create new book to insert into libraries
   BookNode* currNode;
   Book tempBook;

   string bookTitle;
   string bookAuthor;
   long bookISBN;

   //cout << "Enter the book title: " << endl;
   //getline(cin, bookTitle);
   //cout << "Enter the 13 digit ISBN number: " << endl;
   //cin >> bookISBN;
   //cin.ignore();
   //cout << "Enter the book author: " << endl;
   //getline(cin, bookAuthor);
   
   double durationl_fps = 0.0;
   double durationv_fps = 0.0;
   
   for (unsigned int j = 0; j<nelements; j++) {
       bookISBN = 9780400000000+j*4001;
       tempBook = genBook(bookISBN);
       bookAuthor = tempBook.GetBookAuthor();
       bookTitle = tempBook.GetBookTitle();

       auto startl = chrono::high_resolution_clock::now();
       
       // Insert into linked list
       // No need to delete currNode, deleted by LinkedListLibrary destructor
       currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
   
       // TODO: Call LL_Library's InsertSorted() method to insert currNode and return
       //       the (updated) number of operations performed
   
       linkedListOperations = linkedListLibrary.InsertSorted(currNode,linkedListOperations);
       linkedListLibrary.lastNode = currNode;
       
       auto stopl = chrono::high_resolution_clock::now();
       chrono::duration<double,micro> durationl_fp = stopl - startl;
       durationl_fps += double(durationl_fp.count());
       

       auto startv = chrono::high_resolution_clock::now();
       
       tempBook  = Book(bookTitle, bookAuthor, bookISBN);
   
       // TODO: Call VectorLibrary's InsertSorted() method to insert tempBook and return
       //       the (updated) number of operations performed
   
       vectorOperations = vectorLibrary.InsertSorted(tempBook,vectorOperations);
       
       auto stopv = chrono::high_resolution_clock::now();
       chrono::duration<double,micro> durationv_fp = stopv - startv;
       durationv_fps += double(durationv_fp.count());
   }

   // TODO: Print number of operations for linked list
   cout << "Number of linked list operations: " << linkedListOperations << endl;
    
   // TODO: Print number of operations for vector
   cout << "Number of vector operations: " << vectorOperations << endl;
   cout << endl;
   
   cout << "Time (useconds) for List Operations: " << durationl_fps << endl;
   cout << "Time (useconds) for Vector Operations: " << durationv_fps << endl;
   cout << endl;
   cout << "Performance Factor: " << 1.0*durationv_fps/durationl_fps;
   cout << endl;
   
   // Print Libraries
   
   /*cout << "-----------------------------" << endl;
   cout << "Linked List Library:" << endl;
   cout << "-----------------------------" << endl;
   linkedListLibrary.PrintLibrary();
   cout << endl;*/
   
   /*cout << "-----------------------------" << endl;
   cout << "Vector Library: " << endl;
   cout << "-----------------------------" << endl;
   vectorLibrary.PrintLibrary();*/
   
   return 0;

}

