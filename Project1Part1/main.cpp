/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 31, 2021, 5:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "ItemToPurchase.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    string userName;
    int userPrice;
    int userQuantity;
    
    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, userName);
    cout << "Enter the item price:" << endl;
    cin >> userPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> userQuantity;
    cout << endl;
    
    ItemToPurchase item1;
    item1.SetName(userName);
    item1.SetPrice(userPrice);
    item1.SetQuantity(userQuantity);
    
    cin.ignore();
    
    cout << "Item 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin,userName);
    cout << "Enter the item price:" << endl;
    cin >> userPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> userQuantity;
    cout << endl;
    
    ItemToPurchase item2;
    item2.SetName(userName);
    item2.SetPrice(userPrice);
    item2.SetQuantity(userQuantity);
    
    int total_cost = item1.GetPrice()*item1.GetQuantity() + 
                        item2.GetPrice()*item2.GetQuantity();
    
    cout << "TOTAL COST" << endl;
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << 
            item1.GetPrice() << " = $" << 
            item1.GetQuantity()*item1.GetPrice() << endl;
    
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << 
            item2.GetPrice() << " = $" << 
            item2.GetQuantity()*item2.GetPrice() << endl;
    cout << endl;
    cout << "Total: $" << total_cost << endl;
    
    return 0;
}

