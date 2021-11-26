/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StringInstrument.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 8:18 AM
 */

#ifndef STRINGINSTRUMENT_H
#define STRINGINSTRUMENT_H

#include "Instrument.h"

class StringInstrument : public Instrument {
    // TODO: Declare private data members: numStrings, numFrets
private:
    string numStrings;
    string numFrets;

    // TODO: Declare mutator functions - 
    //      SetNumOfStrings(), SetNumOfFrets()
public:

    void SetNumOfStrings(string userNumStrings) {
        numStrings = userNumStrings;
    }

    void SetNumOfFrets(string userNumFrets) {
        numFrets = userNumFrets;
    }

    // TODO: Declare accessor functions -
    //      GetNumOfStrings(), GetNumOfFrets()

    string GetNumOfStrings() {
        return numStrings;
    }

    string GetNumOfFrets() {
        return numFrets;
    }

};

#endif /* STRINGINSTRUMENT_H */

