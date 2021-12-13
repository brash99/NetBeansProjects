/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on December 1, 2021, 7:50 AM
 */

#include <iostream>
using namespace std;

class SmartPhone {
    public:
        virtual void TakeASelfie() = 0;
};

class Android:public SmartPhone {
public:
    void TakeASelfie() {
        cout << "Taking Android Selfie ... " << endl;
    }
    
};

int main(int argc, char** argv) {
    
    SmartPhone* s = new Android();
    s->TakeASelfie();

    return 0;
}

