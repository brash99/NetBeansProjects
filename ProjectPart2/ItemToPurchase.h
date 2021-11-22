/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ItemToPurchase.h
 * Author: 00465510
 *
 * Created on November 1, 2021, 4:32 PM
 */

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
#include <string>

using namespace std;

class ItemToPurchase {
    
public:
    
    ItemToPurchase(string userName = "0", string userDescription = "none", 
            int userQuantity = 0, int userPrice = 0 );
    
    void SetName(string userName);
    void SetPrice(int userPrice);
    void SetQuantity(int userQuantity);
    void SetDescription(string userDescription);
    
    string GetName() const {return itemName;}
    int GetPrice() const {return itemPrice;}
    int GetQuantity() const {return itemQuantity;}
    string GetDescription() const {return itemDescription;}
    
    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;
    
};


#endif /* ITEMTOPURCHASE_H */

