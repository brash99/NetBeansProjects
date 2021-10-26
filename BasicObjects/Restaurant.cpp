#include "Restaurant.h"

//Restaurant::Restaurant() {
//    name = "No Name";
//    rating = -1;
//    price = "No Price";
//    cuisine = "No Type"
//}

Restaurant::Restaurant(string userName, int userRating, string price, string cuisineType) {
    name = userName;
    rating = userRating;
    this->price = price;
    cuisine = cuisineType;
}

void Restaurant::SetName(string restaurantName) {
    name = restaurantName;
    return;
}

void Restaurant::SetRating(int rating) {
    this->rating = rating; //Need to specify this->rating to remove confusion with parameter name
    return;
}

void Restaurant::SetPrice(string price) {
    this->price = price;
    return;
}

void Restaurant::SetCuisineType(string cuisineType) {
    cuisine = cuisineType;
    return;
}

void Restaurant::Print() const {
    cout << name << ": " << endl;
    cout << "Rating = " << rating << " Price = " << price << " Cuisine Type = " 
            << cuisine << endl; 
}


