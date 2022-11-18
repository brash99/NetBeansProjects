/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Car.h
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:29 PM
 */

#ifndef CAR_H
#define CAR_H

class Car {
   private:
      int modelYear; 
      int purchasePrice;
      int currentValue;
   
   public:
      void SetModelYear(int userYear);

      int GetModelYear() const;
   
      void SetPurchasePrice(int myPrice) {purchasePrice = myPrice;} 
   
      int GetPurchasePrice() const {return purchasePrice;}
   
      void CalcCurrentValue(int currentYear);
   
     // TODO: Declare PrintInfo() method to output modelYear, purchasePrice, and 
     // currentValue
      void PrintInfo() const;
   
};


#endif /* CAR_H */

