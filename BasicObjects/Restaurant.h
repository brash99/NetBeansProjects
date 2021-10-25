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
    
    public:
        Restaurant();
        Restaurant(string userName, int userRating); // Initialization Constructor
        
        void SetName(string restaurantName); // prototype mutator function ... define below
        void SetRating(int userRating);
        
        string GetName() const {return name;} // inline accessor function ... define right here!
        int GetRating() const {return rating;}
        void Print() const;
};

#endif /* RESTAURANT_H */

