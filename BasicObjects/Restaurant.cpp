#include "Restaurant.h"

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


