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
#include <iostream>
#include <string>


using namespace std;

class Restaurant {

    private:
        string name;
        int rating;
    
    public:
        Restaurant();
        Restaurant(string userName, int userRating); // Initialization Constructor
        void SetName(string restaurantName); // prototype mutator function ... define below
        void SetRating(int userRating);
        string GetName() const {return name;} // inline accessor function ... define right here!
        int GetRating() const {return rating;}
        void Print() const;
};

Restaurant::Restaurant() {
    name = "NoName";
    rating = -1;
}

Restaurant::Restaurant(string userName, int userRating) {
    name = userName;
    rating = userRating;
}

void Restaurant::SetName(string restaurantName) {
    name = restaurantName;
    return;
}

void Restaurant::SetRating(int userRating) {
    rating = userRating;
    return;
}

void Restaurant::Print() const {
    cout << name << " has a rating of " << rating << endl; 
}

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

