/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:52 PM
 */

#include "Artist.h"
#include "Artwork.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {
   string userTitle, userArtistName;
   int yearCreated, userBirthYear, userDeathYear;

   getline(cin, userArtistName);
   cin >> userBirthYear;
   cin.ignore();
   cin >> userDeathYear;
   cin.ignore();
   getline(cin, userTitle);
   cin >> yearCreated;
   cin.ignore();

   Artist userArtist =  Artist(userArtistName, userBirthYear, userDeathYear);

   Artwork newArtwork = Artwork(userTitle, yearCreated, userArtist);

   newArtwork.PrintInfo();
}
