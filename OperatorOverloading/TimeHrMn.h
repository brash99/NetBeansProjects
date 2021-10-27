/* 
 * File:   TimeHrMn.h
 * Author: 00465510
 *
 * Created on October 25, 2021, 10:41 PM
 */

#ifndef TIMEHRMN_H
#define TIMEHRMN_H

#include <iostream>

using namespace std;

class TimeHrMn {

public:
   TimeHrMn(int timeHours = 0, int timeMinutes = 0, double timeSeconds = 0.0);

   TimeHrMn operator+(TimeHrMn rhs);
   TimeHrMn operator-(TimeHrMn rhs);
   
   void SetHr(int userHours);
   void SetMn(int userMinutes);
   void SetSec(double userSeconds);
   
   int GetHr() const;
   int GetMn() const;
   double GetSec() const;
   
   void Print() const;
   
private:
   int hours;
   int minutes;
   double seconds;
   
};

#endif /* TIMEHRMN_H */

