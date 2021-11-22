/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <vector>

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
    
}

ShoppingCart::ShoppingCart(string myCustomerName, string myDate) {
    customerName = myCustomerName;
    currentDate = myDate;
}

void ShoppingCart::AddItem(ItemToPurchase newItem) {
    cartItems.push_back(newItem);
    return;
}

void ShoppingCart::RemoveItem(string userName) {
    
    int found_index = -1;
    for (int i = 0; i<cartItems.size(); i++) {
        if (cartItems[i].GetName() == userName) {
            found_index = i;
        }
    }
    
    if (found_index == -1) {
        cout << "Item not found in cart. Nothing removed." << endl;
    } else {
        cartItems.erase(cartItems.begin()+found_index);
    }
    
    return;
    
}

void ShoppingCart::ModifyItem(ItemToPurchase userItem) {
    
    int found_index = -1;
    
    for (int i = 0; i<cartItems.size(); i++) {
        if (cartItems[i].GetName() == userItem.GetName()) {
            found_index = i;
        }
    }
    
    if (found_index == -1) {
        cout << "Item not found in cart. Nothing modified." << endl;
    } else {
        
        if (userItem.GetDescription()!="none") {
            cartItems[found_index].SetDescription(userItem.GetDescription());
        }
        
        if (userItem.GetPrice()!=0) {
            cartItems[found_index].SetPrice(userItem.GetPrice());
        }
        
        if (userItem.GetQuantity()!=0) {
            cartItems[found_index].SetQuantity(userItem.GetQuantity());
        }
        
    }
    
    return;
    
}

int ShoppingCart::GetCostOfCart() const {
    
    int totalCost = 0;
    for (int i = 0; i<cartItems.size(); i++) {
        totalCost += cartItems[i].GetPrice()*cartItems[i].GetQuantity();
    }
    
    return totalCost;
}

int ShoppingCart::GetNumItemsInCart() const {
    int numItems = 0;
    for (int i = 0; i<cartItems.size(); i++) {
        numItems += cartItems[i].GetQuantity();
    }
    return numItems;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << this->GetNumItemsInCart() << endl;
    cout << endl;
    
    if (cartItems.size()>0) {
        for (int i=0; i<cartItems.size(); i++) {
            cartItems[i].PrintItemCost();
        }
    } else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    
    cout << endl;
    
    cout << "Total: $" << this->GetCostOfCart() << endl;
    
    return;
}

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    
    cout << "Item Descriptions" << endl;
    if (cartItems.size()>0) {
        for (int i=0; i<cartItems.size(); i++) {
            cartItems[i].PrintItemDescription();
        }
    } else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    
    return;
}


