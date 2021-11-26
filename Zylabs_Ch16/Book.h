/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Book.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 11:44 AM
 */

#ifndef BOOK_H
#define BOOK_H

class Book {
    
   protected:
      string title;
      string author;
      string publisher;
      string publicationDate;

   public:
      void SetTitle(string userTitle) {
          title = userTitle;
      }

      string GetTitle() {
          return title;
      }

      void SetAuthor(string userAuthor) {
          author = userAuthor; 
      }

      string GetAuthor() {
          return author;
      }

      void SetPublisher(string userPublisher) {
          publisher = userPublisher;
      }

      string GetPublisher() {
          return publisher;
      }

      void SetPublicationDate(string userPublicationDate) {
          publicationDate = userPublicationDate;
      }

      string GetPublicationDate() {
          return publicationDate;
      }

      void PrintInfo() {
            cout << "Book Information: " << endl;
            cout << "   Book Title: " << title << endl;
            cout << "   Author: " << author << endl;
            cout << "   Publisher: " << publisher << endl;
            cout << "   Publication Date: " << publicationDate << endl;
      }


};



#endif /* BOOK_H */

