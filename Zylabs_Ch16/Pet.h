/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pet.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 8:05 AM
 */

#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

class Pet {
	protected:
		string petName;
		int petAge;

	public:
		void SetName(string userName) {
                    petName = userName;
                };

		string GetName() {
                    return petName;
                };

		void SetAge(int userAge) {
                    petAge = userAge;
                };

		int GetAge() {
                    return petAge;
                };

		void PrintInfo() {
                    cout << "Pet Information: " << endl;
                    cout << "   Name: " << petName << endl;
                    cout << "   Age: " << petAge << endl;
                };
};

#endif /* PET_H */

