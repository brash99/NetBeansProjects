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

#include "Student.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    Student student = InitStudent();
    char name[20];
    
    GetName(name, student);
    printf("%s/%.1lf\n", name, GetGPA(student));

    student = SetName("Felix", student);
    student = SetGPA(3.7, student);
    GetName(name, student);
    printf("%s/%.1lf\n", name, GetGPA(student));

    return (EXIT_SUCCESS);
}

