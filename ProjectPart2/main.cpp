/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 1, 2021, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "ShoppingCart.h"

// Define a method to print the menu
void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

// Define a method to do the right thing for a given menu choice.
void ExecuteMenu(char option, ShoppingCart& theCart) {
   string name;
   string descr;
   int price;
   int quantity;
   ItemToPurchase item;
   
   switch(option) {
      case 'a':
         cin.ignore();

         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);

         cout << "Enter the item description:" << endl;
         getline(cin, descr);

         cout << "Enter the item price:" << endl;
         cin >> price;

         cout << "Enter the item quantity:" << endl;
         cin >> quantity;
         
         item.SetName(name);
         item.SetDescription(descr);
         item.SetPrice(price);
         item.SetQuantity(quantity);
         
         theCart.AddItem(item);
         cout << endl;
      break;

      case 'd':
         cin.ignore();

         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" << endl;
         getline(cin, name);

         theCart.RemoveItem(name);
         cout << endl;
      break;

      case 'c':
         cin.ignore();

         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);

         cout << "Enter the new quantity:" << endl;
         cin >> quantity;

         item.SetName(name);
         item.SetQuantity(quantity);

         theCart.ModifyItem(item);
         cout << endl;
      break;

      case 'i':
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         cout << endl;
         break;

      case 'o':
         cout << "OUTPUT SHOPPING CART" << endl;
         theCart.PrintTotal();
         cout << endl;
         break;
         
     
   }
}

int main(int argc, char** argv) {
    
   string custName;
   string today;
   char menuChoice;
   
   menuChoice = ' ';

   
   // Get the customer name and date from the user and print them out.
   cout << "Enter customer's name:" << endl;
   getline(cin, custName);

   cout << "Enter today's date:" << endl;
   getline(cin, today);
   
   cout << endl;
   cout << "Customer name: " << custName << endl;
   cout << "Today's date: " << today << endl;
   cout << endl;
   
   // create and initialize a ShoppingCart object with name and date entered.
   ShoppingCart myCart(custName, today);

   // Print the menu once, the first time through.
   PrintMenu();

   // Loop until the user chooses to quit.
   while (menuChoice != 'q') {
      
      // Get the menu choice.
      cout << "Choose an option:" << endl;
      cin >> menuChoice;
      
      // Do things if the person enters a valid menu choice
      if (menuChoice == 'a' || menuChoice == 'd' || menuChoice == 'c' ||
          menuChoice == 'i' || menuChoice == 'o') {
         
         // Call the ExecuteMenu method, which does the appropriate thing
         // for the menu choice made.
         ExecuteMenu(menuChoice, myCart);
         
         // re-Print the menu to get the next choice
         PrintMenu();
         
      }
      
   }

   return 0;
}

