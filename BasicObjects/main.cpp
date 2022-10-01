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
#include <vector>

#include "Restaurant.h"

Restaurant getFavorite(vector<Restaurant> myRestaurants);

int main(int argc, char** argv) {
    
    // Define some objects ... the first two call the default constructor, and the last
    // calls the initialization constructor.
    Restaurant schooners; // default values, id = 1001
    Restaurant moes; // default values, id = 1002
    //Restaurant mickydees;
    Restaurant mickydees("MacDonald's",-10000,"$","Fast Food"); // specified values, id = 1003
    
    cout << "Initial Definition of MacDonald's" << endl;
    mickydees.Print();
    cout << endl;
    
    cout << "Initial Definition of Schooner's" << endl;
    schooners.Print();
    cout << endl;
    
    schooners.SetName("Schooner's");
    schooners.SetRating(4);
    schooners.SetPrice("$$$");
    schooners.SetCuisineType("American Fare");
    
    cout << "New Definition of Schooner's" << endl;
    schooners.Print();
    cout << endl;
    
    cout << "Initial Definition of Moe's" << endl;
    moes.Print();
    cout << endl;
    
    moes.SetName("Moe's");
    moes.SetRating(5);
    moes.SetPrice("$$");
    moes.SetCuisineType("Mexican");
    
    cout << "New Definition of Moe's" << endl;
    moes.Print();
    cout << endl;
    
    // Define a vector of Restaurant objects, and add our three restaurants to it!!!
    vector<Restaurant> myRestaurants;
    
    myRestaurants.push_back(schooners);
    myRestaurants.push_back(moes);
    myRestaurants.push_back(mickydees);
    
    // Figure out the restaurant with the highest rating.
    Restaurant myFavorite;
    
    cout << "Address of myRestaurants in main:  " << &myRestaurants << endl;
    myFavorite = getFavorite(myRestaurants);
    
    cout << "My favorite restaurant: " << endl;
    cout << myFavorite.GetName() << endl;
    cout << "Rating = " << myFavorite.GetRating() << endl;
    cout << "Price = " << myFavorite.GetPrice() << endl;
    cout << "Cuisine Type = " << myFavorite.GetCuisineType() << endl;
    
    return 0;
}

Restaurant getFavorite(vector<Restaurant> myRestaurants) {
    
    cout << "Address of my Restaurants in getFavorite:  " << &myRestaurants << endl;
    cout << endl;
    
    Restaurant bestRestaurant;
    
    int maxRatingIndex = 0;
    int maxRating = -1000000;
    
    cout << "Ratings:" << endl;
    for (int i = 0; i<myRestaurants.size(); i++) {
        myRestaurants[i].Print();
        if (myRestaurants[i].GetRating() > maxRating) {
            maxRatingIndex = i;
            maxRating = myRestaurants[i].GetRating();
        }
    }
    cout << endl;
    
    bestRestaurant = myRestaurants[maxRatingIndex]; // copy!!! This is what "=" does by default.
    
    return bestRestaurant;
    
}

