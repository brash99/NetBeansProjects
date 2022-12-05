/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on November 28, 2022, 3:52 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // to use sort()
using namespace std;

const int NUM_VALUES = 5;

// Input NUM_VALUES of TheType into the vector parameter
template<typename TheType> void Read(vector<TheType>& list) {
   for (int j = 0; j < NUM_VALUES; ++j) {
      cin >> list.at(j);
   }
}

// Output the elements of the vector parameter
template<typename TheType> void Write(vector<TheType>& list) {
   long unsigned int j;
   for (j = 0; j < list.size(); ++j) {
      cout << list.at(j) << " ";
   }
}

// Return the min, median, and max of the vector parameter in a new vector
template<typename TheType> vector<TheType> GetStatistics(vector<TheType>& list) {
    
   //Create a vector of "TheType" elements, which we will fill and return 
   vector<TheType> statistics(3);
   
   // IMPORTANT:  Looking at main(), and also at Run(), the vector (pointer) 
   // that is passed to this method is ALREADY sorted from smallest to largest.  
   // Therefore,the min element will be the zeroeth one, the max element will 
   // be the lastone, and the median element will be the middle one.
   statistics.at(0) = list.at(0);
   statistics.at(1) = list.at(list.size() / 2);
   statistics.at(2) = list.at(list.size() - 1);
   
   return statistics;
}

// Read values into a vector, sort the vector, output the sorted vector,
// then output the min, median, and max of the sorted vector
template<typename TheType> void Run(vector<TheType>& list) {

   // Create a vector of "TheType" elements, which we will fill by calling
   // the GetStatistics function above
   vector<TheType> statistics(3);
   
   // Read values into the vector called 'list', which was passed to this 
   // function
   Read(list);
   
   // Sort the list
   sort(list.begin(), list.end());
   
   // Call the write function on the sorted vector
   Write(list);
   
   // print a blank line
   cout << endl;
   
   // Get the statistics (min,max,median) for the sorted vector
   statistics = GetStatistics(list);
   
   // Call the write function on the statistics vector
   Write(statistics);
   
   // print a blank line
   cout << endl;
}

int main() {
   vector<int> integers(NUM_VALUES);
   Run(integers);
   cout << endl;

   vector<double> doubles(NUM_VALUES);
   Run(doubles);
   cout << endl;

   vector<string> strings(NUM_VALUES);
   Run(strings);

   return 0;
}

