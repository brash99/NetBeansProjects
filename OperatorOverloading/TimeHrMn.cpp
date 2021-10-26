/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "TimeHrMn.h"

// Equality (==) operator for two TimeHrMn objects
bool operator==(const TimeHrMn& lhs, const TimeHrMn& rhs) {
   return (lhs.GetHr() == rhs.GetHr()) && 
          (lhs.GetMn() == rhs.GetMn());
}

// Less-than (<) operator for two Review objects
bool operator<(const TimeHrMn& lhs, const TimeHrMn& rhs) {
   if (lhs.GetHr() < rhs.GetHr()) {
       return -1;
   } else {
       if (lhs.GetHr() > rhs.GetHr()) {
           return 0;
       } else {
           if (lhs.GetMn() < rhs.GetMn()) {
               return -1;
           } else {
               return 0;
           }
       }
   }
}

// Overload + operator for TimeHrMn
TimeHrMn TimeHrMn::operator+(TimeHrMn rhs) {
   TimeHrMn timeTotal;
   
   timeTotal.hours   = hours   + rhs.hours;
   timeTotal.minutes = minutes + rhs.minutes;
   
   while (timeTotal.minutes>=60) {
       timeTotal.hours += 1;
       timeTotal.minutes -= 60;
   }
   
   return timeTotal;
}

TimeHrMn::TimeHrMn(int timeHours, int timeMinutes) {
   hours  = timeHours;
   minutes = timeMinutes;
}

int TimeHrMn::GetHr() const {
    return hours;
}

int TimeHrMn::GetMn() const {
    return minutes;
}

void TimeHrMn::Print() const {
   cout << "H:" << hours << ", " << "M:" << minutes << endl;
}