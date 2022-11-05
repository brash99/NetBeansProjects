/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Artist.h
 * Author: brash
 *
 * Created on November 5, 2022, 9:46 AM
 */

#ifndef ARTIST_H
#define ARTIST_H

#include <string>
using namespace std;

class Artist {
 public:
      Artist();

      Artist(string artistName, int birthYear, int deathYear);

      string GetName() const;

      int GetBirthYear() const;

      int GetDeathYear() const;

      void PrintInfo() const;
   
   private:
      // TODO: Declare private data members - artistName, birthYear, deathYear

};

#endif /* ARTIST_H */

