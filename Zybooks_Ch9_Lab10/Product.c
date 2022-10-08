/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

#include <stdio.h>
#include <string.h>

#include "Product.h"

Product InitProduct(char* code, double price, int count) {
   
    Product newProduct;
    strcpy(newProduct.productCode,code);
    newProduct.price = price;
    newProduct.count = count;
    
    return newProduct;
}

Product SetCode(char* code, Product product) {
   strcpy(product.productCode,code);
   
   return product;
}

void GetCode(char* productCode, Product product) {
   strcpy(productCode,product.productCode);
   return;
}

Product SetPrice(double price, Product product) {
   product.price = price;
   return product;
}

double GetPrice(Product product) {
   return product.price;
}

Product SetCount(int count, Product product) {
   product.count = count;
   return product;
}

int GetCount(Product product) {
   return product.count;
}

Product AddInventory(int amt, Product product) {
   product.count += amt;
   return product;
}

Product SellInventory(int amt, Product product) {
   product.count -= amt;
   return product;
}