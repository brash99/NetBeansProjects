/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Dog.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 8:06 AM
 */

#ifndef DOG_H
#define DOG_H

#include <string>
#include "Pet.h"

class Dog : public Pet {
private:
    string dogBreed;

public:

    void SetBreed(string userBreed) {
        dogBreed = userBreed;
    };

    string GetBreed() {
        return dogBreed;
    };
};


#endif /* DOG_H */

