/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.h
 * Author: brash
 *
 * Created on September 27, 2022, 9:03 AM
 */

#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student_struct {
   char name[20];
   double gpa;
} Student;

Student InitStudent();

Student SetName(char *name, Student s);
Student SetGPA(double gpa, Student s);

void GetName(char* studentName, Student s);
double GetGPA(Student s);

#endif /* STUDENT_H */

