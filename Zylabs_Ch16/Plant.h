/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Plant.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 1:31 PM
 */

#ifndef PLANT_H
#define PLANT_H

#include <string>
using namespace std;

class Plant {
   public:
      virtual ~Plant();

      void SetPlantName(string userPlantName);

      string GetPlantName() const;

      void SetPlantCost(int userPlantCost);

      int GetPlantCost() const;

      virtual void PrintInfo() const;

   protected:
      string plantName;
      int plantCost;
};

Plant::~Plant() {};

void Plant::SetPlantName(string userPlantName) {
   plantName = userPlantName;
}

string Plant::GetPlantName() const {
   return plantName;
}

void Plant::SetPlantCost(int userPlantCost) {
   plantCost = userPlantCost;
}

int Plant::GetPlantCost() const {
   return plantCost;
}

void Plant::PrintInfo() const {
   cout << "Plant Information:" << endl;
   cout << "   Plant name: " << plantName << endl;
   cout << "   Cost: " << plantCost << endl;
}

#endif /* PLANT_H */

