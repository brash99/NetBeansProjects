/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   OfferedCourse.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 11:26 AM
 */

#ifndef OFFEREDCOURSE_H
#define OFFEREDCOURSE_H

#include "Course.h"

class OfferedCourse : public Course {
private:
    string instructorName;
    string term;
    string classTime;

public:

    void SetInstructorName(string userInstructorName) {
        instructorName = userInstructorName;
    }

    void SetTerm(string userTerm) {
        term = userTerm;
    }

    void SetClassTime(string userClassTime) {
        classTime = userClassTime;
    }

    string GetInstructorName() {
        return instructorName;
    }

    string GetTerm() {
        return term;
    }

    string GetClassTime() {
        return classTime;
    }


};



#endif /* OFFEREDCOURSE_H */

