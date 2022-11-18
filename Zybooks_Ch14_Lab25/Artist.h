/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Artist.h
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:54 PM
 */

#ifndef ARTIST_H
#define ARTIST_H

#include <string>
using namespace std;

class Artist{
   public:
      Artist();

      Artist(string artistName, int birthYear, int deathYear);

      string GetName() const;

      int GetBirthYear() const;

      int GetDeathYear() const;

      void PrintInfo() const;

   private:
      string artistName;
      int birthYear;
      int deathYear;
};


#endif /* ARTIST_H */

