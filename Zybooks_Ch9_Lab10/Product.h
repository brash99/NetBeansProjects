/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   Product.h
 * Author: brash
 *
 * Created on October 14, 2021, 8:38 PM
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Product_struct {
   char productCode[20];
   double price;
   int count;
} Product;

Product InitProduct(char* code, double price, int count);
Product SetCode(char* code, Product product);
void GetCode(char* productCode, Product product);
Product SetPrice(double price, Product product);
double GetPrice(Product product);
Product SetCount(int count, Product product);
int GetCount(Product product);
Product AddInventory(int amt, Product product);
Product SellInventory(int amt, Product product);


#ifdef __cplusplus
}
#endif

#endif /* PRODUCT_H */

