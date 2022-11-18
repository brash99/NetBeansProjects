/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "FoodItem.h"
#include <iostream>
#include <iomanip> 

using namespace std;

// Define default constructor
FoodItem::FoodItem() {
    name = "None";
    fat = 0.0;
    carbs = 0.0;
    protein = 0.0;
}

// Define second constructor with arguments
// to initialize private data members
FoodItem::FoodItem(string userName, double userFat, double userCarbs, double userProtein) {
    name = userName;
    fat = userFat;
    carbs = userCarbs;
    protein = userProtein;
}

string FoodItem::GetName() {
   return name;
}

double FoodItem::GetFat() {
   return fat;
}

double FoodItem::GetCarbs() {
   return carbs;
}

double FoodItem::GetProtein() {
   return protein;
}

double FoodItem::GetCalories(double numServings) {
   // Calorie formula
   double calories = ((fat * 9) + (carbs * 4) + (protein * 4)) * numServings;
   return calories;
}

void FoodItem::PrintInfo() {
   cout << fixed << setprecision(2);
   cout << "Nutritional information per serving of " << name  << ":" << endl;
   cout << "   Fat: " << fat << " g" << endl;
   cout << "   Carbohydrates: " << carbs << " g" << endl;
   cout << "   Protein: " << protein << " g" << endl;
}
