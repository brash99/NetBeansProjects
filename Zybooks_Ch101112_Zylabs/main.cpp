/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on September 27, 2022, 9:52 AM
 */

#include <cstdlib>
#include <iostream> 
#include <iomanip> // needed for things like setprecision in cout, etc.
#include <cmath> // needed for pow, sqrt math functions
#include <string> // needed for the string variable type
#include <vector> // needed for C++ vector type

using namespace std;

/*
 * 
 */

void zylab1126() {
    
   double ageYears;
   double weightPounds;
   double heartBPM; // beats per minute
   double timeMinutes;
   double calories;
   
   cin >> ageYears;
   cin >> weightPounds;
   cin >> heartBPM;
   cin >> timeMinutes;
                     
   calories = ((ageYears * 0.2757) + (weightPounds * 0.03295) + (heartBPM * 1.0781) - 75.4991) * timeMinutes / 8.368;

   cout << fixed << setprecision(2);
   cout << "Calories: " << calories << " calories" << endl;
   
}

void zylab1127() {
    
   double x;
   double y;
   double z;

   cin >> x;
   cin >> y;
   cin >> z;
   
   cout << pow(x, z) << " ";
   cout << pow(x, pow(y, z)) << " ";
   cout << fabs(y) << " ";
   cout << sqrt(pow(x * y, z)) << endl;
   
}

void zylab1128() {
    
   int num1;
   int num2;
   int num3;
   int num4;

   cin >> num1;
   cin >> num2;
   cin >> num3;
   cin >> num4;
   
   
   // Statistics using integer arithmetic (part 1)
   cout << num1 * num2 * num3 * num4;
   cout << " " << (num1 + num2 + num3 + num4) / 4 << endl;
   
   cout << fixed << setprecision(3);
   // Statistics using floating-point arithmetic (part 2)
   cout <<  static_cast<double>(num1) * (num2) * (num3) * (num4); 
   cout << " " << (num1 + num2 + num3 + num4) / 4.0 << endl;   // The .0 causes floating-point division
   
   return;
   
}

void zylab1130() {
    
   double dollars;
   int quarters;
   int dimes;
   int nickels;
   int pennies;

   cin >> quarters;
   cin >> dimes;      
   cin >> nickels;
   cin >> pennies;
   
   // Method 1 ... force floating point by using '100.0'
   //dollars = (quarters * 25 + dimes * 10 + nickels * 5 + pennies) / 100.0;
   // Method 2 ... force floating point by using '100.0'
   dollars = (static_cast<double>(quarters) * 25 + dimes * 10 + nickels * 5 + pennies) / 100;
   // Incorrect Method!!!
   //dollars = (quarters * 25 + dimes * 10 + nickels * 5 + pennies) / 100;
   
   cout << fixed << setprecision(2);
   cout << "Amount: $" << dollars << endl;
   
   return;

}

void zylab1218() {
    
   // Note:  we solved this same exact problem in C earlier in the course!
   //        Now, we are going to solve it again, but using C++ vectors, which
   //        is an utterly different approach!
   //   
   //        The advantages of using vectors, rather than arrays, as we did
   //        in the C solution, is that the LENGTH of vectors is dynamic (i.e.
   //        changeable.  Thus, we not have to "guess" the maximum number of
   //        elements that we might want to store ahead of time.
    
   vector<int> userInts;   // A vector to hold the user's input integers
   int numInts;
   int i;
   int userInt; 
   
   // Input begins with number of integers that follow, then list of integers
   cin >> numInts;                 
   for (i = 0; i < numInts; ++i) {
      cin >> userInt;
      userInts.push_back(userInt); // The vector "class" in C++ contains a
                                   // method called 'push_back' which adds
                                   // an element to the vector. This is exactly
                                   // like the 'append' method for Python lists!
   }
   
   // Now output those integers in reverse
   for (i = numInts - 1; i >= 0; --i) {
      cout << userInts.at(i) << ","; // The vector "class" in C++ contains a
                                     // method called 'at' which returns the
                                     // value of stored in the vector, at a
                                     // given index.
   }
   
   // Here is another, better way, using a strange C++ beast called
   // an iterator!!!
   // 
   // The advantages here are that (a) it's way faster for larger vectors, 
   // and (b) we can use the 'begin' and 'end' functions so that we never
   // have to worry about how many elements there are in the vector, at any
   // given moment.
   //
   // An iterator is a type of pointer.  Thus, if we want to get the VALUE of
   // a particular element in a vector, we have to de-reference the pointer
   // to that element, just like we did in C.
   //
   //vector<int>::iterator ptr;
   //
   //for (ptr = userInts.end()-1; ptr >= userInts.begin(); --ptr) {
   //    cout << *ptr << ",";
   //}
  
   cout << endl;
      
   return;
   
}

void zylab1219() {

   vector<int> userValues;
   int currValue;
   int midIndex;
   int i;
   
   cin >> currValue;
   
   i = 0;
   while ((currValue >= 0) && (i < 9)) {
      userValues.push_back(currValue);
      cin >> currValue;
      i = i + 1;
   }
   
   
   if (currValue >= 0) { // Too many inputs. Didn't read in negative value.
      cout << "Too many numbers" << endl;
   }
   else { 
      midIndex = i / 2;
      cout << "Middle item: " << userValues.at(midIndex) << endl;
   }
   
   return;
   
}

void zylab1220() {
    
   vector<int> userValues;
   int numValues;
   int currValue;
   int upperThreshold;
   int i;
   unsigned int j;
   
   // Integer indicating the number of integers that follow
   cin >> numValues;
   
   // Gets list of integers from input
   for (i = 0; i < numValues; ++i) {
      cin >> currValue;
      userValues.push_back(currValue);
   }
   
   // Last value from the input indicating threshold
   cin >> upperThreshold;
   
   // Output all integers less than or equal to the threshold
   //
   // Note: we can use the 'size' method of the vector class to get the
   // current size of a vector!  So, we don't have to keep track of how
   // many elements we have stored in the vector :)
  
   for (j = 0; j < userValues.size(); ++j) {
      if (userValues.at(j) <= upperThreshold) {
         cout << userValues.at(j) << ",";
      }
   }
   cout << endl;

}

void zylab1221() {
    
   vector<double> userValues; 
   int numValues;
   double currValue;
   double maxValue;
   int i;
   unsigned int j;
   
   // Integer indicating the number of floating-point values that follow
   cin >> numValues; 

   // Gets list of doubles from input
   for (i = 0; i < numValues; ++i) {
      cin >> currValue;
      userValues.push_back(currValue);
   }
   
   // Find the minimum value ... old-school looping technique!
   //
   // Note:  there is a better, faster, and more robust way to do this
   //        that is part of another library called 'algorithm' in C++
   //        
   //        But, it uses some concepts that we have not seen yet, so
   //        that is why I did not use it here :)
   
   maxValue = userValues.at(0);
   for (j = 0; j < userValues.size(); ++j) {
      if (userValues.at(j) > maxValue) {
         maxValue = userValues.at(j);
      }
   }
   
   cout << fixed << setprecision(2);
   
   // Divide by largest value when outputting
   for (i = 0; i < numValues; ++i) {
      cout << userValues.at(i) / maxValue << " ";
   }
   cout << endl;
   
   // Using an iterator!
   vector<double>::iterator ptr;
   for (ptr=userValues.begin(); ptr<userValues.end(); ptr++) {
       cout << *ptr/maxValue << " ";
   }
   cout << endl;

}


int main(int argc, char** argv) {
    
    cout << "1. Ch11, Zylab26" << endl << "2. Ch11, Zylab27" << endl << "3. Ch11, Zylab28"
            << endl << "4. Ch11, Zylab30" << endl << "5. Ch12, Zylab18" << endl << "6. Ch12, Zylab19"
            << endl << "7. Ch11, Zylab20" << endl << "8. Ch12, Zylab21" << endl << endl;
            
    cout << "Enter the number of the Zylab to run:" << endl;
    
    int ichoice;
    cin >> ichoice;
    
    switch(ichoice) {
        
        case 1:
            cout << "Calling Ch11 - Zylab26 ..." << endl;
            zylab1126();
            break;
            
        case 2:
            cout << "Calling Ch11 - Zylab27 ..." << endl;
            zylab1127();
            break;
            
        case 3:
            cout << "Calling Ch11 - Zylab28 ..." << endl;
            zylab1128();
            break;
            
        case 4:
            cout << "Calling Ch11 - Zylab30 ..." << endl;
            zylab1130();
            break;
               
        case 5:
            cout << "Calling Ch12 - Zylab18 ..." << endl;
            zylab1218();
            break;   
            
        case 6:
            cout << "Calling Ch12 - Zylab19 ..." << endl;
            zylab1219();
            break; 
            
        case 7:
            cout << "Calling Ch12 - Zylab20 ..." << endl;
            zylab1220();
            break; 
            
        case 8:
            cout << "Calling Ch12 - Zylab21 ..." << endl;
            zylab1221();
            break; 
                      
    }

    return 0;
}

