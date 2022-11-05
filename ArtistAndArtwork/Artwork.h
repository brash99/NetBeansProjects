/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Artwork.h
 * Author: brash
 *
 * Created on November 5, 2022, 9:46 AM
 */

#ifndef ARTWORK_H
#define ARTWORK_H

#include "Artist.h"

class Artwork{
   public:
      Artwork();

      Artwork(string title, int yearCreated, Artist artist);

      string GetTitle();

      int GetYearCreated();

      void PrintInfo();
   
   private:
      // TODO: Declare private data members - title, yearCreated

      // TODO: Declare private data member artist of type Artist

};

#endif /* ARTWORK_H */

