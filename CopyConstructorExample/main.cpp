/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on November 7, 2021, 5:00 PM
 */

#include <iostream>

using namespace std;

class MyClassInt {
  public:
      
     MyClassInt() {
        cout << "MyClassInt Constructor called." << endl;
        dataObject = 0;
     }

     void SetDataObject(const int i) { dataObject = i; }
     int GetDataObject() const { return dataObject; }

  private:
     int dataObject;
};


class MyClassIntPointer {
  public:
      
     MyClassIntPointer() {
        cout << "MyClassIntPointer Constructor called." << endl;
        dataObject = new int; // Allocate data object
        *dataObject = 0;
     }
     
     ~MyClassIntPointer() {
        cout << "MyClassIntPointer Destructor called." << endl;
        delete dataObject;
     }
     
     void SetDataObject(const int i) { *dataObject = i; }
     int GetDataObject() const { return *dataObject; }
     
     // Copy constructor
     MyClassIntPointer(const MyClassIntPointer& origObject) {
        cout << "Copy constructor called." << endl;
        dataObject = new int; // Allocate sub-object
        *dataObject = *(origObject.dataObject);  
     }
     
     MyClassIntPointer& operator=(const MyClassIntPointer& objToCopy) {
     
          cout << "Assignment op called." << endl;
   
          if (this != &objToCopy) {             // 1. Don't self-assign
              delete dataObject;                  // 2. Delete old dataObject
              dataObject = new int;               // 3. Allocate new dataObject
              *dataObject = *(objToCopy.dataObject); // 4. Copy dataObject
          }
   
          return *this;
     
     }

  //private:
     int* dataObject;
};


void SomeFunction(MyClassInt localObject) {
  // Do something with localObject
    localObject.SetDataObject(42);
    cout << "Value within SomeFunction = " << localObject.GetDataObject() << endl;
}

void SomePointerFunction(MyClassIntPointer localObject) {
  // Do something with localObject
    localObject.SetDataObject(42);
    cout << "Value within SomePointerFunction = " << localObject.GetDataObject() << endl;
    cout << "                                   " << localObject.dataObject << endl;
}

int main() {
    
  // When passed by value to a function, a local copy of the object is made,
  // which also makes a local copy of the int sub-object. When the function
  // terminates, both local objects are destroyed, causing no problems
  // for the rest of the program. Common data types like int and double
  // can be locally copied without a copy constructor.
    
  MyClassInt tempObject; // Create object of type MyClassInt
 
  // Set and print data member value
  tempObject.SetDataObject(9);
  cout << "Before: " << tempObject.GetDataObject() << endl;
 
  // Calls SomeFunction(), tempClassObject is passed by value
  SomeFunction(tempObject);          
 
  cout << "After: " << tempObject.GetDataObject() << endl;
  
  cout << endl;
  cout << "--- Copy Constructor Issues with Pointers -----" << endl;
  
  // When passed by value to a function, a local copy of the object
  // is made, which directs a copy of the int* sub-object to point
  // at the same data as the original object. When the function terminates,
  // the destructor destroys the local object, freeing the sub-object's
  // memory. When main() terminates, the destructor is called again to
  // free the already freed memory, causing a crash.
  
  // Passing an object by value creates a local copy of the object, 
  // but not by calling the constructor, which would make a new object. 
  // The local copy's sub-object points to the same memory location as
  // the original object's sub-object, causing problems when the function
  // terminates.
    
  MyClassIntPointer tempPointerObject; // Create object of type MyClassIntPointer
 
  // Set and print data member value
  tempPointerObject.SetDataObject(9);
  cout << "Before: " << tempPointerObject.GetDataObject() << endl;
  cout << "        " << tempPointerObject.dataObject << endl;
 
  // Calls SomePointerFunction(), tempClassObject is passed by value
  SomePointerFunction(tempPointerObject);          
 
  cout << "After: " << tempPointerObject.GetDataObject() << endl;
  cout << "       " << tempPointerObject.dataObject << endl;
  
  cout << endl;
  cout << "---- Assignment operator overloading ----" << endl;
  
  MyClassIntPointer pointerObject1;
  MyClassIntPointer pointerObject2;
  
  // Set and print object 1 data member value
   pointerObject1.SetDataObject(9);
   
   // Copy class object using copy assignment operator
   //
   // The default behaviour here is that it will make a literal copy
   // of the object .. if the object contains pointers, this can cause
   // issues!
   // 
   // The solution is to provide a "definition" of what we want "=" to mean
   //
   // So, we "overload" the '=' operator by providing our own version of it
   // in the class definition.
   //
   pointerObject2 = pointerObject1;
   
   // Set object 1 data member value
   pointerObject1.SetDataObject(1);
   
   // Print data values for each object
   cout << "pointerObject1:" << pointerObject1.GetDataObject() << endl;
   cout << "pointerObject2:" << pointerObject2.GetDataObject() << endl;
   

  return 0;
}

