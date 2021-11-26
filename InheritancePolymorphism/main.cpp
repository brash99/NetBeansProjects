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
#include <vector>

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


    //  Notes on Polymorphism:
    //
    //  1. Compile-Time polymorphism ... the compiler can figure out which function (of the same name)
    //  to call based on the ARGUMENTS to the function, or based on explicit reference to functions of the
    //  class of a particular type of object.
    cout << "Compile Time Polymorphism" << endl;
    cout << "-------------------------" << endl;
    cout << genericBusiness.GetDescription() << endl; // calls the GetDescription method of the Business class!
    cout << favoritePlace.GetDescription() << endl << endl; // calls the GetDescription method of the Restaurant class!

    //
    //  2. Run-Time polymorphism ... if the compiler cannot figure out which is the appropriate function,
    //  then this has to be determined at run time.  We can use VIRTUAL function definitions in these cases
    //  to speed things up.

    Business* businessPtr;

    // Point to genericBusiness
    
    businessPtr = &genericBusiness;
    cout << "Run Time Polymorphism" << endl;
    cout << "---------------------" << endl;
    cout << businessPtr->GetDescription() << endl;

    // Point to favoritePlace
    businessPtr = &favoritePlace;

    cout << businessPtr->GetDescription() << endl << endl;

    return 0;
}

