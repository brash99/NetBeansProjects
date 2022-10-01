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
    
    cout << "The address of y in passBy is: " << &y << endl;
    y = 4;
    return;
    
}

void passByPtr(int* p) {
    
    cout << "The value of p in passByPtr is: " << p << endl;
    *p = 4;
    return;

}

void passByRef(int& q) {
    
    cout << "The value of q in PassByRef is: " << q << endl;
    q = 10;
    return;
    
}

void passByArray(int a[], int length) {
    
    cout << "The address of a in passByArray is: " << &a << " ... in other words, a COPY!" << endl;
    cout << "        a = ";
    for (int i = 0; i<length; i++) {
        a[i] = 4;
        cout << a[i] << " ";
    }
    cout << endl;
    
    return;
    
}

void passByArrayPtr(int* a, int length) {
    
    cout << "The address of a in passByArrayPtr is: " << a << " ... in other words, the same as x in main!!!" << endl;
    cout << "        a = ";
    for (int i = 0; i<length; i++) {
        a[i] = 4;
        cout << a[i] << " ";
    }
    cout << endl;
    
    return;
    
}

void passByVector(vector<int> q) {
    
    cout << "The address of the first element of vector q, in PassByVector, is: " << &q[0] << " ... i.e. a COPY!!!" << endl;
    cout << "        q = ";
    for (int i = 0; i<q.size(); i++) {
        q.at(i) = 4;
        cout << q.at(i) << " ";
        
    }
    cout << endl;
    return;
}

void passByVectorRef(vector<int>& q) {
    cout << "The address of the first element of vector q, in PassByVectorRef, is: " << &q[0] << " ... i.e. a COPY?!?" << endl;
    cout << "        q = ";
    for (int i = 0; i<q.size(); i++) {
        q.at(i) = 4;
        cout << q.at(i) << " ";
    }
    cout << endl;
    return;
}

void passByConstVectorRef(const vector<int>& q) {
    
    cout << "The address of the first element of vector q, in PassByVectorRef, is: " << &q[0] << " ... i.e. a COPY?!?" << endl;
    cout << "        q = ";
    for (int i = 0; i<q.size(); i++) {
        //q.at(i) = 2;
        cout << q.at(i) << " ";
    }
    cout << endl;
    return;
    
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    cout << endl;
    cout << "Integers ... " << endl;
    int z = 10;
    cout << "The address of z in main is: " << &z << endl;
    passBy(z);
    cout << "z = "  << z << " ... still!" <<endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Pointers ... " << endl;
    z = 10;
    cout << "The address of z in main is: " << &z << endl;
    int* zptr = &z;
    passByPtr(zptr);
    cout << "z = " << z << " ... i.e. it's been updated!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "References ... these are like 'aliases'" << endl;
    int& r = z;
    cout << "z = " << z << endl;
    cout << "r = " << r << endl;
    
    passByRef(z);
    
    cout << "z = " << z << endl;
    cout << "r = " << r << " ... in other words, r is the same of z!!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    
    cout << "Arrays ... " << endl;
    const int size = 10;
    
    int x[size];
    
    cout << "The address of the first element of x, in main, is: " << &x[0] << endl;
    cout << "Before: x = ";
    for (int i=0; i<size; i++) {
        x[i] = i + 1;
        cout << x[i] << " ";
    }
    cout << endl;
    
    passByArray(x,size);
    
    cout <<"After:  x = ";
    for (int i=0; i<size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "So, this is confusing, right?  It makes a copy, but yet the array" << endl;
    cout << "got changed!  It must actually be using references or pointers, somehow!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Arrays by Pointer ... " << endl;
    
    cout << "The address of the first element of x, in main, is: " << &x[0] << endl;
    cout << "Before: x = ";
    for (int i=0; i<size; i++) {
        x[i] = i + 1;
        cout << x[i] << " ";
    }
    cout << endl;
    
    passByArrayPtr(x,size);
    
    cout <<"After:  x = ";
    for (int i=0; i<size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "So, things changed, but we expected that, so life is good!" <<  endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    
    cout << "Vectors ... " << endl;
    
    vector<int> xvector;
    
    
    cout << "Before: xvector = ";
    for (int i=0; i<size; i++) {
        xvector.push_back(i+1);
        if (i==0) {
            cout << "The address of the first element of xvector, in main, is: " << &xvector[0] << endl;
            cout << "Before: xvector = ";
        }
        cout << xvector.at(i) << " ";
    }
    cout << endl;
    
    passByVector(xvector);
    
    for (int i=0; i<xvector.size(); i++) {
        if (i==0) {
            cout << "After: xvector = ";
        }
        cout << xvector.at(i) << " ";
    }
    cout << endl;
    cout << "So, xvector did NOT change in main, because we truly sent only a copy!" << endl;
    cout << "Apparently, vectors work differently than arrays ... the compiler does NOT try to outsmart us!!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    
    cout << "Vector References ... " << endl;
    vector<int> xvector2;
    
    cout << "Before: xvector2 = ";
    for (int i=0; i<size; i++) {
        xvector2.push_back(i+1);
        if (i==0) {
            cout << "The address of the first element of xvector2, in main, is: " << &xvector2[0] << endl;
            cout << "Before: xvector = ";
        }
        cout << xvector2.at(i) << " ";
    }
    cout << endl;
    
    passByVectorRef(xvector2);
    
    for (int i=0; i<xvector2.size(); i++) {
        if (i==0) {
            cout << "After: xvector2 = ";
        }
        cout << xvector2.at(i) << " ";
    }
    cout << endl;
    cout << "So, xvector DID change in main, because we sent a reference!!!" << endl;
    cout << "Remember, references are like aliases ... so, even though q appeared to be a copy," << endl;
    cout << "it was really just an alias for xvector2 in the function, and so changing q changed xvector2!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Const Vector References ... " << endl;
    vector<int> xvector3;
    
    cout << "Before: xvector3 = ";
    for (int i=0; i<size; i++) {
        xvector3.push_back(i+1);
        if (i==0) {
            cout << "The address of the first element of xvector3, in main, is: " << &xvector3[0] << endl;
            cout << "Before: xvector = ";
        }
        cout << xvector3.at(i) << " ";
    }
    cout << endl;
    
    passByConstVectorRef(xvector3);
    
   for (int i=0; i<xvector3.size(); i++) {
        if (i==0) {
            cout << "After: xvector3 = ";
        }
        cout << xvector3.at(i) << " ";
    }
    cout << endl;
    cout << "So, the point here is that we are not ALLOWED to change the vector in the function!!!!!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    return 0;
}

