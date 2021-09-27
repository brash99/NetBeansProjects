/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 26, 2021, 2:30 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 8
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

typedef struct Number_struct {
	int num;
} Number;

void Swap(Number* numPtr1, Number* numPtr2) {
	
	int temp = numPtr1->num;
	numPtr1->num=numPtr2->num;
	numPtr2->num=temp;
	
}

void zylab1() {
    
        Number* num1 = NULL;
	Number* num2 = NULL;

	num1 = (Number*)malloc(sizeof(Number));
	num2 = (Number*)malloc(sizeof(Number));

	int int1;
	int int2;

	scanf("%d", &int1);
	scanf("%d", &int2);

	num1->num = int1;
	num2->num = int2;

	Swap(num1, num2);
	printf("num1 = %d, num2 = %d\n",  num1->num, num2->num);

	return;
    
}



int main(int argc, char** argv) {
    
    printf("1. Zylab1\n\n");
    printf("Enter the number of the Zylab to run: \n");
    
    int ichoice;
    scanf("%d",&ichoice);
    
    switch(ichoice) {
        
        case 1:
            printf("Calling Zylab1 ... \n");
            zylab1();
            break;
            
    }

    return (EXIT_SUCCESS);
}


