/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Artist.h"
#include <iostream>

Artist::Artist(){
   artistName = "None";
   birthYear = -1;
   deathYear = -1;
}

Artist::Artist(string artistName, int birthYear, int deathYear) {
   this->artistName = artistName;
   this->birthYear = birthYear;
   this->deathYear = deathYear;
}

string Artist::GetName() const {
   return artistName;
}

int Artist::GetBirthYear() const {
   return birthYear;
}

int Artist::GetDeathYear() const {
   return deathYear;
}

void Artist::PrintInfo() const {
   cout << "Artist: " << artistName;
   if (birthYear != -1) {
        if(deathYear == -1){
            cout << ", born " << birthYear;
        } else {
            cout << " (" << birthYear << "-" << deathYear << ")";
        }
   }
}