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
        char a;
} Number;

void Swap(Number* numPtr1, Number* numPtr2) {
	
	//Here is one way to do it
        //int temp = numPtr1->num;
	//numPtr1->num=numPtr2->num;
	//numPtr2->num=temp;
        //char tempc = numPtr1->a;
        //numPtr1->a = numPtr2->a;
        //numPtr2->a = tempc;
        
        // Here's another way!
        //
        // In principle this is better, as it does not
        // rely on understanding the internal structure of
        // the number object!
        Number temp = *numPtr1;
        *numPtr1 = *numPtr2;
        *numPtr2 = temp;
	
}

void zylab1() {
    
        Number* num1 = NULL;
	Number* num2 = NULL;

	num1 = (Number*)malloc(sizeof(Number));
	num2 = (Number*)malloc(sizeof(Number));

	int int1;
	int int2;
        
        //char b;
        //char c;

	scanf("%d", &int1);
	scanf("%d", &int2);
        
        //scanf(" %c",&b);
        //scanf(" %c",&c);

	num1->num = int1;
	num2->num = int2;
        //num1->a = b;
        //num2->a = c;

	Swap(num1, num2);
	printf("num1->num = %d, num2->num = %d\n",  num1->num, num2->num);
        //printf("num1->a = %c, num2->a = %c\n",num1->a,num2->a);

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


