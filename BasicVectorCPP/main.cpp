/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 18, 2021, 10:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Illustrate some of the basic features of the vector class.
 */

void printVector(vector<int> a) {
    
    vector<int>::iterator ptr;
    
    for (ptr=a.begin(); ptr<a.end(); ptr++) {
        cout << *ptr << " ";
    }
    
    cout << endl;
}

int main(int argc, char** argv) {
    
    // Declaring, reading from stdin, accessing using loops
    
    const int NUM_VALS = 8;
    vector<int> userVals(NUM_VALS);
    unsigned int i;
    
    cout << "Enter " << NUM_VALS << " integer values ... " << endl;
    for (i=0; i<userVals.size(); i++) {
        cout << " Value: ";
        cin >> userVals.at(i);
    }
    
    cout << "You entered: ";
    for (i=0; i<userVals.size(); i++) {
        cout << userVals.at(i) << " ";
    }
    cout << endl;
    
    // Initializing
    
    vector<int> maxScores = {20,20,200,5};
    
    cout << "maxScores: ";
    printVector(maxScores);
    
    // Resizing!!! :)
    
    vector<int> vals;  // currently a vector of size 0!!!!
    int nvals;
    
    cout << "Enter the number of values: ";
    cin >> nvals;
    
    vals.resize(nvals); // now we can resize it!!!
    
    cout << "Enter " << nvals << " integer values ... " << endl;
    for (i=0; i<vals.size(); i++) {
        cout << " Value: ";
        cin >> vals.at(i);
    }
    
    cout << "You entered: ";
    printVector(vals);
    
    vals.resize(nvals+2);
    
    cout << "Enter two more integer values ... " << endl;
    for (i=0; i<2; i++) {
        cout << " Value: ";
        cin >> vals.at(nvals+i);
    }
    
    cout << "You entered (in total): ";
    printVector(vals);
    
    vals.resize(nvals-2);
    
    cout << "You entered (two less than original): ";
    printVector(vals);
    
    vals.push_back(1000);
    vals.push_back(2000);
    
    printVector(vals);
    
    /////////////////// Bad /////////////////////
    
    int userWeights[3];
    int userAge;
    
    userAge = 44;
    
    userWeights[0] = 122;
    userWeights[1] = 119;    
    userWeights[2] = 117;
    //userWeights[3] = 199;
    
    printf("User's age is %d.\n",userAge);
    
    ///////////////// Good //////////////////////
    
    vector<int> userWeights2(3);
    int userAge2;
    
    userAge2 = 44;

    userWeights2.at(0) = 122;
    userWeights2.at(1) = 119;
    userWeights2.at(2) = 117;
    //userWeights2.at(3) = 199;
    
    printf("User's age is %d.\n",userAge2);
    
    
    //////////////// Zylab 1 /////////////////////
    
    vector<int> userInts; // A vector to hold the user's input integers
   
    int numElements;
    cin >> numElements;
   
    int myint;
    for (int i=0; i<numElements; i++) {
       cin >> myint;
       userInts.push_back(myint);
    }
    
    vector<int>::iterator ptr;
   
    for (ptr = userInts.end()-1; ptr >= userInts.begin(); --ptr) {
       cout << *ptr << ",";
    }

    cout << endl;
       
    return 0;
}

