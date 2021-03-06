/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 5, 2021, 5:25 PM
 */

#include <iostream>
#include <vector>

using namespace std;


///////////////////// Point class ////////////////////

class Point {
public:
   Point(double xValue = 0, double yValue = 0); // constructor
   void Print(); // print method

   double X; 
   double Y;
};

// Define constructor method
Point:: Point(double xValue, double yValue) {
   X = xValue;
   Y = yValue;
}

// Define print method
void Point::Print() {
   cout << "(" << X << ", ";
   cout << Y << ")" << endl;
}

///////////////////// Car Class ////////////////////

class Car {
   public:
      Car(int distanceToSet = 0);
      int GetDistanceTraveled() const;
   private:
      int distanceTraveled;
};

Car::Car(int distanceToSet) {
   distanceTraveled = distanceToSet;
}

int Car::GetDistanceTraveled() const {
   return distanceTraveled;
}

int GetTotalMiles(vector<Car*> carsList) {
   int totalMiles;
   unsigned int i;

   totalMiles = 0;

   for (i = 0; i < carsList.size(); i++) {
      totalMiles = totalMiles + carsList.at(i)->GetDistanceTraveled();
   }

   return totalMiles;
}

//////////////////////////////////////

int main() {
   Point* point1 = new Point; // define a pointer to an object of type Point.
                              // This will call the constructor and assign
                              // default values to member variables.
   
   (*point1).Print();   // Dereference the point1 pointer, and call the print
                        // method for that dereferenced object.  Expect (0,0)
   
   point1->Print();     // use the member access operator (->).  Expect (0,0)
   

   Point* point2 = new Point(8, 9); // define a second pointer to a Point object
                                    // provide initialization values.
   
   (*point2).Print();   // Dereference the point2 pointer, and print.
                        // Expect (8,9)
   
   point2->Print();     // use the member access operator (->).  Expect (8,9)
   
   delete point1;       // Free up the memory allocated to these pointers!
   delete point2;
   
   point1->Print();     // Could be anything!!!!!!!
   point2->Print();
   
   // Create an vector of pointers to Car objects ... a garage :)
   
   vector<Car*> garage;
   garage.push_back(new Car(10));
   garage.push_back(new Car(40));
   garage.push_back(new Car(5));

   cout << endl;
   cout << "Traveled: " << GetTotalMiles(garage) << endl;
   
   // Now, delete the first Car object from the vector!
   delete garage.at(0);
   garage.erase(garage.begin() + 0);
   
   cout << endl;
   cout << "Traveled: " << GetTotalMiles(garage) << endl;
   
   return 0;
}

