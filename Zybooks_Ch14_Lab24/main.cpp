/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:40 PM
 */

#include "FoodItem.h"
#include <iostream>
#include <iomanip> 

using namespace std;

int main(int argc, char* argv[]) {
    
   FoodItem FoodItem1; //create food item with default constructor

   string itemName;
   double amountFat, amountCarbs, amountProtein;

   cout << "Enter product name: " << endl;;
   cin >> itemName;
   cout << "Enter fat content (in g): " << endl;
   cin >> amountFat;
   cout << "Enter carb content (in g): " << endl;;
   cin >> amountCarbs;
   cout << "Enter protein content (in g): " << endl;
   cin >> amountProtein;

   // create second object using initialization constructor
   FoodItem FoodItem2 = FoodItem(itemName, amountFat, amountCarbs, amountProtein);

   double numServings;
   cout << "Enter number of servings: " << endl;
   cin >> numServings;

   FoodItem1.PrintInfo();
   
   cout << fixed << setprecision(2);
   cout << "Number of calories for " << numServings << " serving(s): " << FoodItem1.GetCalories(numServings) << endl;
   cout << endl << endl;

   FoodItem2.PrintInfo();
   
   cout << "Number of calories for " << numServings << " serving(s): " << FoodItem2.GetCalories(numServings) << endl;

   return 0;
}

