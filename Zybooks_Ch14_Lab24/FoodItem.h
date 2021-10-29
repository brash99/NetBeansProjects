/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FoodItem.h
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:40 PM
 */

#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>

using namespace std;

class FoodItem {
   public:
       
      FoodItem(); // Default Constructor - must have the same name as the class name!!!!!
      FoodItem(string userName, double userFat, double userCarbs, double userProtein); // Initialization Constructor

      string GetName();
      double GetFat();
      double GetCarbs();
      double GetProtein();
      
      double GetCalories(double numServings);

      void PrintInfo();

   private:
      string name;
      double fat;
      double carbs;
      double protein;
};

#endif /* FOODITEM_H */

