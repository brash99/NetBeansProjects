/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 26, 2021, 2:21 PM
 */

#include <iostream>
#include <string>

using namespace std;

/*
 *  Function Template Examples 
 */


// Define a function called TripleMin() that returns the minimum value
// of three arguments.  TheType can be any valid C++ variable type, as long
// as the "algebra" of the type has been defined (i.e. '=', '>', '<', etc.)
//
// Just imagine replacing 'TheType' with 'int' or 'string' everywhere!

template<typename TheType>
TheType TripleMin(TheType item1, TheType item2, TheType item3) {
    TheType minVal = item1; // Holds min item value, init to first item

    if (item2 < minVal) {
        minVal = item2;
    }
    if (item3 < minVal) {
        minVal = item3;
    }

    return minVal;
}

// We can also do the same thing with classes!

template<typename TheType>
class TripleItem {
public:
    TripleItem(TheType val1 = 0, TheType val2 = 0, TheType val3 = 0);
    void PrintAll() const; // Print all data member values
    TheType MinItem() const; // Return min data member value
private:
    TheType item1; // Data value 1
    TheType item2; // Data value 2
    TheType item3; // Data value 3
};

template<typename TheType>
TripleItem<TheType>::TripleItem(TheType i1, TheType i2, TheType i3) {
    item1 = i1;
    item2 = i2;
    item3 = i3;
}

// Print all data member values

template<typename TheType>
void TripleItem<TheType>::PrintAll() const {
    cout << "(" << item1 << "," << item2
            << "," << item3 << ")" << endl;
}

// Return min data member value

template<typename TheType>
TheType TripleItem<TheType>::MinItem() const {
    TheType minVal = item1; // Holds value of min item, init to first item

    if (item2 < minVal) {
        minVal = item2;
    }
    if (item3 < minVal) {
        minVal = item3;
    }

    return minVal;
}

int main(int argc, char** argv) {

    // Three integers
    int num1 = 55; // Test case 1, item1
    int num2 = 99; // Test case 1, item2
    int num3 = 66; // Test case 1, item3

    // Three chars
    char let1 = 'a'; // Test case 2, item1
    char let2 = 'z'; // Test case 2, item2
    char let3 = 'm'; // Test case 2, item3

    // Three strings
    string str1 = "zzz"; // Test case 3, item1
    string str2 = "aaa"; // Test case 3, item2
    string str3 = "mmm"; // Test case 3, item3

    // Try TripleMin function with ints
    cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
    cout << "Min: " << TripleMin(num1, num2, num3) << endl << endl;

    // Try TripleMin function with chars
    cout << "Items: " << let1 << " " << let2 << " " << let3 << endl;
    cout << "Min: " << TripleMin(let1, let2, let3) << endl << endl;

    // Try TripleMin function with strings
    cout << "Items: " << str1 << " " << str2 << " " << str3 << endl;
    cout << "Min: " << TripleMin(str1, str2, str3) << endl << endl;

    // Three booleans (should work, since true = 1 and false = 0)
    bool b1 = true;
    bool b2 = false;
    bool b3 = true;

    // Try TripleMin function with booleans
    cout << "Items: " << b1 << " " << b2 << " " << b3 << endl;
    cout << "Min: " << TripleMin(b1, b2, b3) << endl << endl;

    cout << "-------------------------------------------------" << endl;

    TripleItem<int> triInts(9999, 5555, 6666); // TripleItem class with ints
    TripleItem<short> triShorts(99, 55, 66); // TripleItem class with shorts

    // Try functions from TripleItem
    triInts.PrintAll();
    cout << "Min: " << triInts.MinItem() << endl << endl;

    triShorts.PrintAll();
    cout << "Min: " << triShorts.MinItem() << endl << endl;


    return 0;
}

