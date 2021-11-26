/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Flower.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 1:31 PM
 */

#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"
#include <string>
#include <iostream>

using namespace std;

class Flower : public Plant {
   public:
      void SetPlantType(bool userIsAnnual);

      bool GetPlantType() const;

      void SetColorOfFlowers(string userColorOfFlowers);

      string GetColorOfFlowers() const;

      void PrintInfo() const;

   private:
      bool isAnnual;
      string colorOfFlowers;
};

void Flower::SetPlantType(bool userIsAnnual) {
   isAnnual = userIsAnnual;
}

bool Flower::GetPlantType() const {
   return isAnnual;
}

void Flower::SetColorOfFlowers(string userColorOfFlowers) {
   colorOfFlowers = userColorOfFlowers;
}

string Flower::GetColorOfFlowers() const {
   return colorOfFlowers;
}

void Flower::PrintInfo() const {
   cout << "Plant Information:" << endl;
   cout << "   Plant name: " << plantName << endl;
   cout << "   Cost: " << plantCost << endl;
   cout << "   Annual: " << boolalpha << isAnnual << endl;
   cout << "   Color of flowers: " << colorOfFlowers << endl;
}

#endif /* FLOWER_H */

