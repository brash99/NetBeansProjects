/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ItemToPurchase.h
 * Author: 00465510
 *
 * Created on October 31, 2021, 5:51 PM
 */

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
#include <string>

using namespace std;

class ItemToPurchase {
    
public:
    
    ItemToPurchase();
    
    void SetName(string userName);
    void SetPrice(int userPrice);
    void SetQuantity(int userQuantity);
    
    string GetName() const {return itemName;}
    int GetPrice() const {return itemPrice;}
    int GetQuantity() const {return itemQuantity;}

private:
    
    string itemName;
    int itemPrice;
    int itemQuantity;
    
};

#endif /* ITEMTOPURCHASE_H */

