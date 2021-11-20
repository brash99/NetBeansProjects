/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 20, 2021, 11:18 AM
 */

#include "Business.h"

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Business genericBusiness;
    Restaurant favoritePlace;
    
    genericBusiness.SetName("Some business"); // calls the SetName method of the Business class
    genericBusiness.SetAddress("1 Main St"); // Calls the SetAddress method of the Business class
    
    favoritePlace.SetName("Friends Cafe"); // actually calls the SetName method of the Business class
    favoritePlace.SetAddress("500 W 2nd Ave"); // actually calls the SetAddress method of the Business class
   
    favoritePlace.SetRating(5); // calls the SetRating method of the Restaurant class
    
    cout << favoritePlace.GetDescription() << endl << endl; // calls the GetDescription method of the Restaurant class!
    cout << genericBusiness.GetDescription() << endl; // calls the GetDescription method of the Business class!
    
    return 0;
}

