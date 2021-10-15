/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on October 14, 2021, 8:36 PM
 */


#include <stdio.h>
#include <string.h>

#include "Product.h"

int main() {
	char code[20];
	char productCode[20];
	strcpy(code, "Apple");
	double price = 0.40;
	int num = 3;
	Product product  = InitProduct(code, price, num);

	// Test 1 - Are instance variables set/returned properly?
	GetCode(productCode, product);
	printf("Name: %s\n", productCode);
	printf("Price: %.2lf\n", GetPrice(product));
	printf("Count: %d\n\n", GetCount(product));

	// Test 2 - Are instance variables set/returned properly after adding and selling?
	num = 10;
	product = AddInventory(num, product);
	num = 5;
	product = SellInventory(num, product);
	GetCode(productCode, product);
	printf("Name: %s\n", productCode);
	printf("Price: %.2lf\n", GetPrice(product));
	printf("Count: %d\n\n", GetCount(product));

	// Test 3 - Do setters work properly?
	strcpy(code, "Golden Delicious");
	product = SetCode(code, product);
	price = 0.55;
	product = SetPrice(price, product);
	num = 4;
	product = SetCount(num, product);
	GetCode(productCode, product);
	printf("Name: %s\n", productCode);
	printf("Price: %.2lf\n", GetPrice(product));
	printf("Count: %d\n", GetCount(product));

	return 0;
}