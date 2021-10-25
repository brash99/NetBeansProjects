/*
 * Basic Objects
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 25, 2021, 12:46 PM
 */

#include <cstdlib>

#include "Restaurant.h"

int main(int argc, char** argv) {
    
    Restaurant schooners;
    Restaurant moes;
    Restaurant favorite;
    Restaurant mickydees("MacDonald's",-10000);
    
    mickydees.Print();
    cout << endl;
    
    cout << "Initial Definition of Schooner's" << endl;
    schooners.Print();
    cout << endl;
    
    schooners.SetName("Schooner's");
    schooners.SetRating(4);
    moes.SetName("Moe's");
    moes.SetRating(1);
    favorite.SetName("Paul's Deli");
    favorite.SetRating(5);
    
    cout << "My favorite restaurants: " << endl;
    schooners.Print();
    favorite.Print();
    
    cout << endl;
    
    cout << "My favorite restaurant: " << favorite.GetName() << " -- Rating = " << favorite.GetRating() << endl;
    
    return 0;
}

