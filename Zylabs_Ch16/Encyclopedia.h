/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Encyclopedia.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 11:44 AM
 */

#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include "Book.h"

class Encyclopedia : public Book {
    
   public:
      // Define mutator functions -
      //       SetEdition(), SetNumVolumes()
      void SetEdition(string userEdition) {
          edition = userEdition;
      }

      void SetNumVolumes(int userNumVolumes) {
          numVolumes = userNumVolumes;
      }

      // Define accessor functions -
      //       GetEdition(), GetNumVolumes()
      string GetEdition() {
          return edition;
      }

      int GetNumVolumes() {
          return numVolumes;
      }

      // Define a PrintInfo() function that overrides
      //       the PrintInfo in Book class
      void PrintInfo() {
            cout << "Book Information: " << endl;
            cout << "   Book Title: " << title << endl;
            cout << "   Author: " << author << endl;
            cout << "   Publisher: " << publisher << endl;
            cout << "   Publication Date: " << publicationDate << endl;
            cout << "   Edition: " + edition << endl;
            cout << "   Number of Volumes: " << numVolumes << endl;
      }

   private:
      // Declare private fields: edition, numVolumes
      string edition;
      int numVolumes;
};

#endif /* ENCYCLOPEDIA_H */

