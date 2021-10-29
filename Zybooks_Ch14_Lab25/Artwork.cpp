/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Artwork.h"
#include <iostream>

Artwork::Artwork() {
   title = "None";
   yearCreated = 0;
}

Artwork::Artwork(string title, int yearCreated, Artist artist) {
   this->title = title;
   this->yearCreated = yearCreated;
   this->artist = artist;
}

string Artwork::GetTitle() {
   return title;
}

int Artwork::GetYearCreated() {
   return yearCreated;
}

void Artwork::PrintInfo() {
   artist.PrintInfo();
   cout << endl << "Title: " << title << ", " << yearCreated;
}