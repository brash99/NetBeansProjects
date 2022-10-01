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
        int id;
        
        static int nextID; // a static member variable is a member of the CLASS, and
                            // not to any particular object of the class!!!!!!!
    
    public:
        Restaurant(); // Default Constructor
        Restaurant(string userName, int userRating, 
            string price, string cuisineType); // Initialization Constructor
        
        //Restaurant(string userName = "No Name", int userRating = -1, 
        //        string price = "No Price",string cuisineType = "No Type");  
        //                //Initialization constructor with default values.
        
        void SetName(string restaurantName); // prototype mutator/setter function ... define in .cpp file
        void SetRating(int userRating);
        void SetPrice(string price);
        void SetCuisineType(string cuisineType);
        void SetID(int id);
        
        string GetName() const {return name;} // inline accessor/getter function ... define right here!
        int GetRating() const {return rating;}
        string GetPrice() const {return price;}
        string GetCuisineType() const {return cuisine;}
        int GetID() const {return id;}
        
        void Print() const; // Use const to indicate/require that object cannot be altered in the function!!!
};

#endif /* RESTAURANT_H */

