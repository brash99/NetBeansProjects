/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 26, 2021, 8:04 AM
 */

#include <iostream>
#include <string>
#include <vector>
#include "Dog.h"
#include "StringInstrument.h"
#include "OfferedCourse.h"
#include "Encyclopedia.h"
#include "Flower.h"

using namespace std;

/*
 *  Zylabs Chapter 16 solutions 
 */

void PrintVector(vector<Plant*> myGarden) {
   size_t i;

   for (i = 0; i < myGarden.size(); ++i) {
      myGarden.at(i)->PrintInfo();
      cout << endl;
   }
}

int main(int argc, char** argv) {
    
    int choice = 5;
    
    if (choice == 1) {
    
        string petName, dogName, dogBreed;
        int petAge, dogAge;

        Pet myPet;
        Dog myDog;

        getline(cin, petName);
        cin >> petAge;
        cin.ignore();
        getline(cin, dogName);
        cin >> dogAge;
        cin.ignore();
        getline(cin, dogBreed);

        // TODO: Create generic pet (using petName, petAge) and then call PrintInfo       
        myPet.SetAge(petAge);
        myPet.SetName(petName);
        myPet.PrintInfo();
        

        // TODO: Create dog pet (using dogName, dogAge, dogBreed) and then call PrintInfo
        myDog.SetName(dogName);
        myDog.SetAge(dogAge);
        myDog.SetBreed(dogBreed);
        myDog.PrintInfo();

        // TODO: Use GetBreed(), to output the breed of the dog
        cout << "   Breed: " << myDog.GetBreed() << endl;
    
    }
    
    if (choice == 2) {
        Instrument myInstrument;
	StringInstrument myStringInstrument;

	string instrumentName, manufacturerName, stringInstrumentName, stringManufacturer, yearBuilt,
			cost, stringYearBuilt, stringCost, numStrings, numFrets;

	getline(cin, instrumentName);
	getline(cin, manufacturerName);
	getline(cin, yearBuilt);
	getline(cin, cost);

	getline(cin, stringInstrumentName);
	getline(cin, stringManufacturer);
	getline(cin, stringYearBuilt);
	getline(cin, stringCost);
	getline(cin, numStrings);
	getline(cin, numFrets);

	myInstrument.SetName(instrumentName);
	myInstrument.SetManufacturer(manufacturerName);
	myInstrument.SetYearBuilt(yearBuilt);
	myInstrument.SetCost(cost);
	myInstrument.PrintInfo();

	myStringInstrument.SetName(stringInstrumentName);
	myStringInstrument.SetManufacturer(stringManufacturer);
	myStringInstrument.SetYearBuilt(stringYearBuilt);
	myStringInstrument.SetCost(stringCost);
	myStringInstrument.SetNumOfStrings(numStrings);
	myStringInstrument.SetNumOfFrets(numFrets);
	myStringInstrument.PrintInfo();

	cout << "   Number of strings: " << myStringInstrument.GetNumOfStrings() << endl;
	cout << "   Number of frets: " << myStringInstrument.GetNumOfFrets() << endl;
                
    }
    
    if (choice == 3) {
        
		Course myCourse;
		OfferedCourse myOfferedCourse;

		string courseNumber, courseTitle;
		string oCourseNumber, oCourseTitle, instructorName, term, classTime;

		getline(cin, courseNumber);
		getline(cin, courseTitle);

		getline(cin, oCourseNumber);
		getline(cin, oCourseTitle);
		getline(cin, instructorName);
		getline(cin, term);
		getline(cin, classTime);

		myCourse.SetCourseNumber(courseNumber);
		myCourse.SetCourseTitle(courseTitle);
		myCourse.PrintInfo();

		myOfferedCourse.SetCourseNumber(oCourseNumber);
		myOfferedCourse.SetCourseTitle(oCourseTitle);
		myOfferedCourse.SetInstructorName(instructorName);
		myOfferedCourse.SetTerm(term);
		myOfferedCourse.SetClassTime(classTime);
		myOfferedCourse.PrintInfo();

		cout << "   Instructor Name: " << myOfferedCourse.GetInstructorName() << endl;
		cout << "   Term: " << myOfferedCourse.GetTerm() << endl;
		cout << "   Class Time: " << myOfferedCourse.GetClassTime() << endl;        
        
    }
    
    if (choice == 4) {
        
            Book myBook;
            Encyclopedia myEncyclopedia;

            string title, author, publisher, publicationDate;
            string eTitle, eAuthor, ePublisher, ePublicationDate, edition;
            int numVolumes;

            getline(cin, title);
            getline(cin, author);
            getline(cin, publisher);
            getline(cin, publicationDate);

            getline(cin, eTitle);
            getline(cin, eAuthor);
            getline(cin, ePublisher);
            getline(cin, ePublicationDate);
            getline(cin, edition);
            cin >> numVolumes;

            myBook.SetTitle(title);
            myBook.SetAuthor(author);
            myBook.SetPublisher(publisher);
            myBook.SetPublicationDate(publicationDate);
            myBook.PrintInfo();

            myEncyclopedia.SetTitle(eTitle);
            myEncyclopedia.SetAuthor(eAuthor);
            myEncyclopedia.SetPublisher(ePublisher);
            myEncyclopedia.SetPublicationDate(ePublicationDate);
            myEncyclopedia.SetEdition(edition);
            myEncyclopedia.SetNumVolumes(numVolumes);
            myEncyclopedia.PrintInfo();
        
    }
    
    if (choice == 5) {
            vector<Plant*> myGarden;
            // Declare variables - plantName, plantCost, flowerName, flowerCost,
            //       colorOfFlowers, isAnnual
            string plantName, flowerName, colorOfFlowers;
            int plantCost;
            bool isAnnual;
            string input;

            cin >> input;

            while(input != "-1") {
                // Check if input is a plant or flower
                //       Store as a plant object or flower object
                //       Add to the vector myGarden
                if (input == "plant") {
                    Plant* myPlant = new Plant();
                    cin >> plantName;
                    cin >> plantCost;
                    myPlant->SetPlantName(plantName);
                    myPlant->SetPlantCost(plantCost);
                    myGarden.push_back(myPlant);
                }
                else if (input == "flower") {
                    Flower* myFlower = new Flower();
                    cin >> plantName;
                    cin >> plantCost;
                    cin >> boolalpha >> isAnnual;
                    cin >> colorOfFlowers;
                    myFlower->SetPlantName(plantName);
                    myFlower->SetPlantCost(plantCost);
                    myFlower->SetPlantType(isAnnual);
                    myFlower->SetColorOfFlowers(colorOfFlowers);
                    myGarden.push_back(myFlower);
                }
                cin >> input;
            }
            // Call the method PrintVector to print myGarden
            PrintVector(myGarden);

            for (size_t i = 0; i < myGarden.size(); ++i) {
                delete myGarden.at(i);
            }
        
        
    }

    return 0;
}

