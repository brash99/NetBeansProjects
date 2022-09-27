/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 4, 2021, 11:35 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * This is program that solves the assigned Zylabs that are part of chapter 5
 * 
 * There is a single main function (as required in C) that calls
 * functions (which each return void) corresponding to the Zylabs
 * 
 */

void zylab1() {
    
   int x;
   scanf("%d", &x);
   
   while (x>0) {
      printf("%d",x%2);
      x = x / 2;
   }
   printf("\n");
   
}

void zylab2() {
    
   int x = 0;
   double sum = 0.0;
   int count = 0;
   int max = 0;
   while (x>=0) {
      scanf("%d",&x);
      if (x>=0) {
         sum = sum + 1.0*x;
         count = count + 1;
      }
      if (x>max) {
         max = x;
      }
   }
   
   double average = sum/(double)count;
   printf("%d %0.2lf\n", max,average);    
  
}

void zylab3() {
    
   int a, b;
   scanf("%d %d",&a, &b);
   
   if (b<a) {
      printf("Second integer can't be less than the first.\n");
   } else {
      while (a<=b) {
         printf("%d ",a);
         a = a + 5;
      }
      printf("\n");
   }

}

void zylab4() {
    
   int a,b,c;
   int d,e,f;
   scanf("%d %d %d",&a,&b,&c);
   scanf("%d %d %d",&d,&e,&f);
   
   int flag = 0;
   for (int x=-10; x<=10; x++) {
      for (int y=-10; y<=10; y++) {
         int left1 = a*x+b*y;
         int left2 = d*x+e*y;
         //printf("%d %d %d %d %d %d\n",x,y,left1,left2,c,f);
         if (left1==c && left2==f) {
            flag = 1;
            printf("x = %d, y = %d\n",x,y);
         }
      }
   }
   
   if (flag == 0) {
      printf("There is no solution\n");
   }
   
}


int main(int argc, char** argv) {
    
    printf("1. Zylab1\n2. Zylab2\n3. Zylab3\n4. Zylab4\n\n");
    printf("Enter the number of the Zylab to run:    \n");
    int ichoice;
    scanf("%d",&ichoice);
    
    switch(ichoice) {
        
        case 1:
            printf("Calling Zylab1 ... \n");
            zylab1();
            break;
            
        case 2:
            printf("Calling Zylab2 ... \n");
            zylab2();
            break;
            
        case 3:
            printf("Calling Zylab3 ... \n");
            zylab3();
            break;
            
        case 4:
            printf("Calling Zylab4 ... \n");
            zylab4();
            break;
            
    }

    return (EXIT_SUCCESS);
    
}



