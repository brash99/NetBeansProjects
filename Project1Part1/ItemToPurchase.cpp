/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "No Name";
    itemPrice = 0;
    itemQuantity = 0;
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

