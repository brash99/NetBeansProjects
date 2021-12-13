/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on December 1, 2021, 8:18 AM
 */

#include <iostream>
using namespace std;

class SmartPhone {
public:
    virtual void TakeASelfie()=0;
    virtual void MakeACall(long number)=0;
};

class Android:public SmartPhone {
    void TakeASelfie() {
        cout << "Taking an Android Selfie ... " << endl;
    }
    void MakeACall(long number) {
        cout << "Android calling " << number << " ... " << endl;
    }
    
};

class iPhone:public SmartPhone {
    void TakeASelfie() {
        cout << "Taking an iPhone Selfie in a better way ... " << endl;
    }
    
    void MakeACall(long number) {
        cout << "iPhone calling " << number << " ... " << endl;
    }
    
};


int main(int argc, char** argv) {
    
    SmartPhone* s = new Android();
    s->TakeASelfie();\

    s->MakeACall(7577532831);

    return 0;
}

