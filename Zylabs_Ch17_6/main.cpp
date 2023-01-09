/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on November 27, 2022, 7:33 PM
 */

#include <iostream>
#include <string>
using namespace std;

class Pair {
   public:
      void Input();
      void Output();
      char CompareWith(Pair* otherPair) ;
      void ShowComparison(Pair* otherPair);

   private:
      int firstVal;
      int secondVal;
};

// Return '<', '=', or '>' according to whether the Pair is less than,
// equal to, or greater than the argument Pair
char Pair::CompareWith(Pair* otherPair) {
   if (this->firstVal < otherPair->firstVal) {
      return '<';
   }
   else if (this->firstVal > otherPair->firstVal) {
      return '>';
   }
   else if (this->secondVal < otherPair->secondVal) {
      return '<';
   }
   else if (this->secondVal > otherPair->secondVal) {
      return '>';
   }
   return '=';
}

// Input values into a pair
void Pair::Input() {
   cin >> this->firstVal;
   cin >> this->secondVal;
}

// Output a Pair 
void Pair::Output() {
   cout << "[" << this->firstVal << ", " << this->secondVal << "]";
}

// Output both pairs with a comparison symbol in between
void Pair::ShowComparison(Pair* otherPair) {
   Output();
   cout << " " << CompareWith(otherPair) << " ";
   otherPair->Output();
   cout << endl;
}

int main() {
    
   Pair intPair;
   Pair intOtherPair;
   intPair.Input();
   intOtherPair.Input();
   intPair.ShowComparison(&intOtherPair);

   //Pair<double> doublePair;
   //Pair<double> doubleOtherPair;
   //doublePair.Input();
   //doubleOtherPair.Input();
   //doublePair.ShowComparison(&doubleOtherPair);

   //Pair<string> wordPair;
   //Pair<string> wordOtherPair;
   //wordPair.Input();
   //wordOtherPair.Input();
   //wordPair.ShowComparison(&wordOtherPair);

   return 0;
}



