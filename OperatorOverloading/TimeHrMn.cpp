/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "TimeHrMn.h"

TimeHrMn::TimeHrMn(int timeHours, int timeMinutes, double timeSeconds) {
   hours  = timeHours;
   minutes = timeMinutes;
   seconds = timeSeconds;
}

void TimeHrMn::SetHr(int userHours) {
    hours = userHours;
    return;
}

void TimeHrMn::SetMn(int userMinutes) {
    minutes = userMinutes;
    return;
}
   
void TimeHrMn::SetSec(double userSeconds) {
    seconds = userSeconds;
}

int TimeHrMn::GetHr() const {
    return hours;
}

int TimeHrMn::GetMn() const {
    return minutes;
}

double TimeHrMn::GetSec() const {
    return seconds;
}


void TimeHrMn::Print() const {
   cout << "H:" << hours << ", " << "M:" << minutes << ", " << "S:" << seconds << endl;
}

// Overload + operator for TimeHrMn
TimeHrMn TimeHrMn::operator+(TimeHrMn rhs) {
   TimeHrMn timeTotal;
   
   timeTotal.hours   = hours   + rhs.hours;
   timeTotal.minutes = minutes + rhs.minutes;
   timeTotal.seconds = seconds + rhs.seconds;
   
   while (timeTotal.seconds>=60.0) {
       
       timeTotal.minutes +=1;
       
       while (timeTotal.minutes>=60) {
            timeTotal.hours += 1;
            timeTotal.minutes -= 60;
       }
       
       timeTotal.seconds -=60.0;
   }
   
   return timeTotal;
}

// Overload - operator for TimeHrMn
TimeHrMn TimeHrMn::operator-(TimeHrMn rhs) {
   TimeHrMn timeTotal;
   
   double total_seconds = hours*3600.0+minutes*60.0+seconds;
   double rhs_seconds = rhs.hours*3600.0+rhs.minutes*60.0+rhs.seconds;
   double elapsed_time = total_seconds - rhs_seconds;
   
   int elapsed_hours = elapsed_time/3600;
   int remaining_seconds = int(elapsed_time) % 3600;
   int elapsed_minutes = remaining_seconds/60;
   double elapsed_seconds = elapsed_time - 3600.0*elapsed_hours - 60.0*elapsed_minutes;
   
   timeTotal.hours   = elapsed_hours;
   timeTotal.minutes = elapsed_minutes;
   timeTotal.seconds = elapsed_seconds;
   
   return timeTotal;
}