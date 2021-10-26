/* 
 * File:   Restaurant.h
 * Author: 00465510
 *
 * Created on October 25, 2021, 2:27 PM
 */

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>

using namespace std;

class Restaurant {

    private:
        string name;
        int rating;
        string price;
        string cuisine;
    
    public:
        //Restaurant(); // Default Constructor
        //Restaurant(string userName, int userRating, string price, string cuisineType); // Initialization Constructor
        Restaurant(string userName = "No Name", int userRating = -1, string price = "No Price",
                string cuisineType = "No Type");  //Default constructor with default values.
        
        void SetName(string restaurantName); // prototype mutator function ... define in .cpp file
        void SetRating(int userRating);
        void SetPrice(string price);
        void SetCuisineType(string cuisineType);
        
        string GetName() const {return name;} // inline accessor function ... define right here!
        int GetRating() const {return rating;}
        string GetPrice() const {return price;}
        string GetCuisineType() const {return cuisine;}
        
        void Print() const; // Use const to indicate/require that object cannot be altered in the function!!!
};

#endif /* RESTAURANT_H */

