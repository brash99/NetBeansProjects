/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00465510
 *
 * Created on November 26, 2021, 7:00 PM
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StatePair.h"

using namespace std;

int main() {
    ifstream inFS; // File input stream
    int zip;
    int population;
    string abbrev;
    string state;
    unsigned int i;

    // ZIP code - state abbrev. pairs
    vector<StatePair <int, string> > zipCodeState;

    // state abbrev. - state name pairs
    vector<StatePair<string, string> > abbrevState;

    // state name - population pairs
    vector<StatePair<string, int> > statePopulation;

    // Fill the three ArrayLists

    // Try to open zip_code_state.txt file
    inFS.open("zip_code_state.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file zip_code_state.txt." << endl;
        return 1; // 1 indicates error
    }
    while (!inFS.eof()) {
        StatePair <int, string> temp;
        inFS >> zip;
        if (!inFS.fail()) {
            temp.SetKey(zip);
        }
        inFS >> abbrev;
        if (!inFS.fail()) {
            temp.SetValue(abbrev);
        }
        zipCodeState.push_back(temp);
    }
    inFS.close();
    
    cout << "Read in zip_code_state.txt" << endl;

    inFS.open("abbreviation_state.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file abbreviation_state.txt." << endl;
        return 1; // 1 indicates error
    }
    while (!inFS.eof()) {
        StatePair <string, string> temp;
        inFS >> abbrev;
        if (!inFS.fail()) {
            temp.SetKey(abbrev);
        }
        getline(inFS, state); //flushes endline
        getline(inFS, state);
        state = state.substr(0, state.size() - 1);
        if (!inFS.fail()) {
            temp.SetValue(state);
        }

        abbrevState.push_back(temp);
    }
    inFS.close();
    cout << "Read in abbreviation_state.txt" << endl;

    inFS.open("state_population.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file state_population.txt." << endl;
        return 1; // 1 indicates error
    }
    while (!inFS.eof()) {
        StatePair <string, int> temp;
        getline(inFS, state);
        state = state.substr(0, state.size() - 1);
        if (!inFS.fail()) {
            temp.SetKey(state);
        }
        inFS >> population;
        if (!inFS.fail()) {
            temp.SetValue(population);
        }
        getline(inFS, state); //flushes endline
        statePopulation.push_back(temp);
    }
    inFS.close();
    
    cout << "Read in state_population.txt" << endl;

    cout << "Enter Zip Code:" << endl;
    cin >> zip;

    for (i = 0; i < zipCodeState.size(); i++) {
        if (zipCodeState.at(i).GetKey() == zip)
            abbrev = zipCodeState.at(i).GetValue();
    }

    for (i = 0; i < abbrevState.size(); i++) {
        if (abbrevState.at(i).GetKey() == abbrev)
            state = abbrevState.at(i).GetValue();
    }

    for (i = 0; i < statePopulation.size(); i++) {
        if (statePopulation.at(i).GetKey() == state)
            statePopulation.at(i).PrintInfo();
    }
}
