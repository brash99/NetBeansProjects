#include "Restaurant.h"

//Restaurant::Restaurant() {
//    name = "NoName";
//    rating = -1;
//}

Restaurant::Restaurant(string userName, int userRating) {
    name = userName;
    rating = userRating;
}

void Restaurant::SetName(string restaurantName) {
    name = restaurantName;
    return;
}

void Restaurant::SetRating(int rating) {
    this->rating = rating; //Need to specify this->rating to remove confusion with parameter name
    return;
}

void Restaurant::Print() const {
    cout << name << " has a rating of " << rating << endl; 
}


