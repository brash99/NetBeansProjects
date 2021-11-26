/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Course.h
 * Author: 00465510
 *
 * Created on November 26, 2021, 11:26 AM
 */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
private:
    string courseNumber;
    string courseTitle;

public:

    void SetCourseNumber(string userCourseNumber) {
        courseNumber = userCourseNumber;
    }

    void SetCourseTitle(string userCourseTitle) {
        courseTitle = userCourseTitle;
    }

    string GetCourseNumber() {
        return courseNumber;
    }

    string GetCourseTitle() {
        return courseTitle;
    }

    void PrintInfo() {
        cout << "Course Information: " << endl;
        cout << "   Course Number: " << courseNumber << endl;
        cout << "   Course Title: " << courseTitle << endl;
    }


};

#endif /* COURSE_H */

