/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(string userName, string userDescription, int userPrice, 
        int userQuantity) {
    itemName = userName;
    itemPrice = userPrice;
    itemQuantity = userQuantity;
    itemDescription = userDescription;
}

void ItemToPurchase::SetName(string userName) {
    itemName = userName;
    return;
}

void ItemToPurchase::SetPrice(int userPrice) {
    itemPrice = userPrice;
    return;
}

void ItemToPurchase::SetQuantity(int userQuantity) {
    itemQuantity = userQuantity;
    return;
}

void ItemToPurchase::SetDescription(string userDescription) {
    itemDescription = userDescription;
    return;
}

void ItemToPurchase::PrintItemCost() const {
    cout << this->GetName() << " " << this->GetQuantity() << " @ $" << 
            this->GetPrice() << " = $" << 
            this->GetQuantity()*this->GetPrice() << endl;
}

void ItemToPurchase::PrintItemDescription() const {
    cout << this->GetName() << ": " << this->GetDescription() << endl;
}