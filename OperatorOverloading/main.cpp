/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on October 25, 2021, 10:38 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Demonstration of some of the important aspects of operator overloading
 * 
 * Redefining/defining the meaning of +, -, and *
 *  
 */

#include "TimeHrMn.h"

// Equality (==) operator for two TimeHrMn objects
bool operator==(const TimeHrMn& lhs, const TimeHrMn& rhs) {
   return (lhs.GetHr() == rhs.GetHr()) && 
          (lhs.GetMn() == rhs.GetMn()) &&
          (lhs.GetSec() == rhs.GetSec());
}

// Less-than (<) operator for two Review objects
bool operator<(const TimeHrMn& lhs, const TimeHrMn& rhs) {
   if (lhs.GetHr() < rhs.GetHr()) {
       return true;
   } else {
       if (lhs.GetHr() > rhs.GetHr()) {
           return false;
       } else {
           if (lhs.GetMn() < rhs.GetMn()) {
               return true;
           } else {
               return false;
           }
       }
   }
}


// Complete the set of relational operators by using previous methods for "==" and "<"
bool operator!=(const TimeHrMn& lhs, const TimeHrMn& rhs) { return !(lhs == rhs); }
bool operator>(const TimeHrMn& lhs, const TimeHrMn& rhs)  { return rhs < lhs;    }
bool operator<=(const TimeHrMn& lhs, const TimeHrMn& rhs) { return !(lhs > rhs); }
bool operator>=(const TimeHrMn& lhs, const TimeHrMn& rhs) { return !(lhs < rhs); }


int main(int argc, char** argv) {
    
    TimeHrMn time1(3, 22, 45.0);
    TimeHrMn time2(2, 50, 34.2);
    TimeHrMn time3(3, 22, 45.0);
    
    time1.Print();
    time2.Print();
    
    TimeHrMn sumTime;

    sumTime = time1 + time2;
    sumTime.Print();
    
    if (time2 < time1) {
        cout << "Everything ok!" << endl;
    }
    
    if (time3 == time1) {
        cout << "Everything ok, still!" << endl;
    }
    
    TimeHrMn elapsedTime = time1 - time2;
    
    elapsedTime.Print();
    
    return 0;
}

