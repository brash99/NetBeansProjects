/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Instrument.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 8:18 AM
 */

#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <iostream>
#include <string>

using namespace std;

class Instrument {
protected:
	string instrumentName;
	string instrumentManufacturer;
	string yearBuilt;
	string cost;

public:
	void SetName(string userName) {
            instrumentName = userName;
        };

	string GetName() {
            return instrumentName;
        };

	void SetManufacturer(string userManufacturer) {
            instrumentManufacturer = userManufacturer;
        };

	string GetManufacturer() {
            return instrumentManufacturer;
        };

	void SetYearBuilt(string userYearBuilt) {
            yearBuilt = userYearBuilt;
        };

	string GetYearBuilt() {
            return yearBuilt;
        };

	void SetCost(string userCost) {
            cost = userCost;
        };

	string GetCost() {
            return cost;
        };

	void PrintInfo() {
            cout << "Instrument Information: " << endl;
            cout << "   Name: " << instrumentName << endl;
            cout << "   Manufacturer: " << instrumentManufacturer << endl;
            cout << "   Year built: " << yearBuilt << endl;
            cout << "   Cost: " << cost << endl;
        };
};

#endif /* INSTRUMENT_H */

