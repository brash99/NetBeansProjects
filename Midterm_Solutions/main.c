/* 
 * File:   main.c
 * Author: brash
 *
 * Created on October 8, 2022, 8:19 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "GVCoin.h"

//
// Functions defined here ...
//

int DaysInFeb (int userYear) {
   int days = 28;
   
   if ((userYear % 4) == 0) {          // userYear is divisible by 4
      if ((userYear % 100) == 0) {     // userYear is divisible by 100 (century year)
         if ((userYear % 400) == 0) {  // userYear is divisible by 400
            days = 29;
         }
      }
      else {                           // userYear is not divisible by 100
         days = 29;
      }
   }
   
   return days;
}

int ConsecutiveHeads(GVCoin coin, int goal) {
	int streak = 0;   // streak counts how many heads in a row

	while (streak < goal) { // flip until streak == goal
		coin = Flip(coin);
		if (IsHeads(coin))   // Either increment streak or set streak to zero
			streak++;
		else streak = 0;
	}

	return NumFlips(coin);  // Return total flips required to match goal
}

int main(int argc, char** argv) {
    
    ///////////////////////////////////////////////////
    //                                               //
    //         Problem 1:  Zybooks 21.6              //
    //                                               //
    ///////////////////////////////////////////////////
    
    int areaCode;
    int prefixNum;
    int lineNum;

    // Input phone number parts
    scanf("%d", &areaCode);
    scanf("%d", &prefixNum);
    scanf("%d", &lineNum);

    // Output phone directory
    printf("Country  Phone Number\n");
    printf("-------  ------------\n");
    printf("U.S.     +1 (%d)%d-%d\n", areaCode, prefixNum, lineNum);
    printf("Brazil   +55 (%d)%d-%d\n", areaCode, (prefixNum + 100), lineNum);
    printf("Croatia  +385 (%d)%d-%d\n", areaCode, prefixNum, (lineNum + 50));
    printf("Egypt    +20 (%d)%d-%d\n", (areaCode + 30), prefixNum, lineNum);
    printf("France   +33 (%d)%d-%d\n", prefixNum, areaCode, lineNum);
       
    ///////////////////////////////////////////////////
    //                                               //
    //         Problem 2:  Zybooks 22.12             //
    //                                               //
    ///////////////////////////////////////////////////
    
    double r;
    double h;
    double volume;
    double area;

    scanf("%lf %lf", &r, &h);

    volume = M_PI * pow(r, 2) * h;
    area = 2 * M_PI * r * h + 2 * M_PI * pow(r, 2);

    printf("Volume: %.1f cubic inches\n", volume);
    printf("Surface area: %0.1lf square inches\n", area);
    
    ///////////////////////////////////////////////////
    //                                               //
    //         Problem 3:  Zybooks 25.4              //
    //                                               //
    ///////////////////////////////////////////////////

    const int NUM_ELEMENTS = 20;
    int userNumbers[NUM_ELEMENTS];    // Set of data specified by the user   
    int numVals;
    int userInput;
    int smallerNum;
    int smallestNum;
   
    // Integer indicating the number of integers that follow
    scanf("%d", &numVals);

    // Get list of integers from input
    for (int i = 0; i < numVals; ++i) { 
       scanf("%d", &userInput);
       userNumbers[i] = userInput;
    }

    // Determine if element 0 or element 1 is the smallest integer, initialize accordingly   
    if (userNumbers[0] < userNumbers[1]) {
       smallerNum = userNumbers[1];
       smallestNum = userNumbers[0];
    }
    else {
       smallerNum = userNumbers[0];
       smallestNum = userNumbers[1];
    }
   
    // Look through remaining elements to determine the two smallest integers in the list
    for (int i = 2; i < numVals; ++i) {
       if (userNumbers[i] < smallestNum) {
          smallerNum = smallestNum;
          smallestNum = userNumbers[i];
       }
       else if (userNumbers[i] < smallerNum) { 
          smallerNum = userNumbers[i];
       }
    }

    // Output the two smallest integers in the list in ascending order
    printf("%d and %d\n", smallestNum, smallerNum);
    
    ///////////////////////////////////////////////////
    //                                               //
    //         Problem 4:  Zybooks 26.10             //
    //                                               //
    ///////////////////////////////////////////////////
    
    //int userInput;  // userInput is used a previous problem, so don't
                      // need to redefine here.
   
    scanf("%d", &userInput);
    printf("%d has %d days in February.\n", userInput, DaysInFeb(userInput));
    
    ///////////////////////////////////////////////////
    //                                               //
    //         Problem 5:  Zybooks 26.10             //
    //                                               //
    ///////////////////////////////////////////////////
    
    GVCoin coin = InitGVCoin(15);
    int numHeads = 5;
    int flips = ConsecutiveHeads(coin, numHeads);
    printf("Total number of flips for 5 consecutive heads: %d\n", flips);
    
    
    return (EXIT_SUCCESS);
}

