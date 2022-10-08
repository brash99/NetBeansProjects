/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 27, 2022, 9:02 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"

Student InitStudent() {
   Student newStudent;
   strcpy(newStudent.name,"Louie");
   newStudent.gpa = 1.00;
   
   return newStudent;
}

Student SetName(char *name, Student s){
    strcpy(s.name,name);
    return s;
}

Student SetGPA(double gpa, Student s){
    s.gpa = gpa;
    return s;
}

void GetName(char* studentName, Student s){
    strcpy(studentName, s.name);
}

double GetGPA(Student s){
    return s.gpa;
}



