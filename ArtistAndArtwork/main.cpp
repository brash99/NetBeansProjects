/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on November 5, 2022, 9:45 AM
 */

#include "Artist.h"
#include "Artwork.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    
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

   return 0;
}

