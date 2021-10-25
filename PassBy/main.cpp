/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 25, 2021, 7:44 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void passBy(int y) {
    
    y = 4;
    
}

void passByPtr(int* p) {
    
    *p = 4;
}

void passByArray(int a[], int length) {
    
    for (int i = 0; i<length; i++) {
        a[i] = 4;
    }
    
    //for (int i = 0; i<length; i++) {
    //    cout << a[i] << endl;
    //}
    
}

void passByVector(vector<int> q) {
    for (int i = 0; i<q.size(); i++) {
        q.at(i) = 4;
    }
}

void passByVectorRef(vector<int>& q) {
    for (int i = 0; i<q.size(); i++) {
        q.at(i) = 4;
    }
}

void passByConstVectorRef(const vector<int>& q) {
    
    for (int i = 0; i<q.size(); i++) {
        //q.at(i) = 2;
        cout << q.at(i) << " ";
    }
    cout << endl;
    
}

void passByRef(int& r) {
    
    r = 10;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    cout << "Integers ... " << endl;
    int z = 10;
    passBy(z);
    cout << z << endl;
    cout << endl;
    cout << endl;
    
    cout << "Pointers ... " << endl;
    z = 10;
    int* zptr = &z;
    passByPtr(zptr);
    cout << z << endl;
    cout << endl;
    cout << endl;
    
    
    cout << "Arrays ... " << endl;
    const int size = 10;
    
    int x[size];
    
    for (int i=0; i<size; i++) {
        x[i] = i + 1;
    }
    
    passByArray(x,size);
    
    for (int i=0; i<size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    
    
    cout << "Vectors ... " << endl;
    
    vector<int> xvector;
    
    for (int i=0; i<size; i++) {
        xvector.push_back(i+1);
    }
    
    passByVector(xvector);
    
    for (int i=0; i<xvector.size(); i++) {
        cout << xvector.at(i) << " ";
    }
    cout << endl;
    
    
    cout << "References ... " << endl;
    
    int& r = z;
    
    cout << z << endl;
    cout << r << endl;
    
    passByRef(z);
    
    cout << z << endl;
    cout << r << endl;
    
    cout << "Vector References ... " << endl;
    
    passByVectorRef(xvector);
    
    for (int i=0; i<xvector.size(); i++) {
        cout << xvector.at(i) << " ";
    }
    cout << endl;
    
    cout << "Const Vector References ... " << endl;
    
    passByConstVectorRef(xvector);
    
    for (int i=0; i<xvector.size(); i++) {
        cout << xvector.at(i) << " ";
    }
    cout << endl;
   
    return 0;
}

