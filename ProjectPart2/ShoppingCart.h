/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ShoppingCart.h
 * Author: 00465510
 *
 * Created on November 1, 2021, 4:33 PM
 */

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
    
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
    
public:
    
    ShoppingCart();
    ShoppingCart(string myCustomerName, string myDate);
    
    string GetCustomerName() const {return customerName;}
    string GetDate() const {return currentDate;}
    
    void AddItem(ItemToPurchase newItem);
    void RemoveItem(string userName);
    void ModifyItem(ItemToPurchase userItem);
    
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    
    void PrintTotal() const;
    void PrintDescriptions() const;
    
};

#endif /* SHOPPINGCART_H */

