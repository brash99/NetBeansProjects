// -*- C++ -*-
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file to edit this template
 */

/* 
 * File:   Artwork.
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:53 PM
 */

#ifndef ARTWORK_
#define ARTWORK_

#include "Artist.h"
#include <string>
using namespace std;

class Artwork{
   public:
      Artwork();

      Artwork(string title, int yearCreated, Artist artist);

      string GetTitle();

      int GetYearCreated();

      void PrintInfo();
   
   private:
      string title;
      int yearCreated;
      Artist artist;
};

#endif /* ARTWORK_ */

