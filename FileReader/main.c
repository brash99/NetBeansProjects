/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 4, 2021, 7:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 80  // define can be used to define GLOBAL variables
                 // this is super useful for certain things that might
                 // change from system to system

/*
 *  Program to read data from a file and process
 * 
 *  The data file has many lines, of the form:
 * LastName FirstName   Score1 Score2 Score3
 */
int main(int argc, char** argv) {
    
    /* Define necessary variables */
    
    const unsigned int nMax = 1000; // maximum number of lines in the file
    
    FILE* inFile = NULL; //This variable will be a "pointer" to the input file
    FILE* outFile = NULL; //This variable will be a "pointer" to the output file
    
    char lastName[nMax][LINE], firstName[nMax][LINE];
    int score1[nMax],score2[nMax],score3[nMax];
    char letterGrade[nMax];
    double scoreAvg[nMax];
    double test1Average,test2Average,test3Average;
    
    printf("The pointer corresponding to the input file, before opening, = %p\n",
            inFile);
    
    /* Get the filename from the user */  
    char filename[LINE];
    printf("Enter the filename:\n");
    
    //gets(filename);
    // Note:  gets will work, and you will see it in a lot of
    // code, but it has been deprecated in C11, so we probably should not use it
    // anymore.
   
    scanf("%s",filename);
    printf("Filename = %s\n",filename);
    
    /* Open the file for reading */
    inFile = fopen(filename, "r");
    //inFile = fopen("StudentInfo.tsv", "r");
   
    printf("The pointer corresponding to the input file, after opening, = %p\n",
            inFile);
    
    if (inFile == NULL) {
        printf("Error:  Could not open file:  %s\n",filename);
        exit(-1);
    } else {
        printf("File opened successfully ... \n");
    }
    
    char line[LINE]; //char array to hold each "line" read from the file
    
    int i = 0, j=0;  // These will hold the column number and row number
    
    printf("EOF = %d\n",EOF);
    
    while (!feof(inFile)) {
        
        //printf("%s\n",line);
        //printf("%d %d\n",i,j);
        //
        // Note, because the fields are separated by tabs, a "line" is just
        // up to the next tab character ... on the one hand, easier because
        // we read one field at a time, but on the other hand, annoying because
        // we have to process things one field at a time.
        //
        // We can use the strcpy() function, from string.h, to assign strings
        // to a char[] array in C.
        // 
        // We can use the atoi() function to convert a string to an integer
        // value.
        
        int numRead;
        numRead = fscanf(inFile, "%s", line);
        printf("numRead = %d\n", numRead);
        
        if (i==0) {
            strncpy(lastName[j], line, LINE);
        }
        if (i==1) {
            strncpy(firstName[j], line, LINE);
        }
        if (i==2) {
            score1[j]=atoi(line);
        }
        if (i==3) {
            score2[j]=atoi(line);
        }        
        if (i==4) {
            score3[j]=atoi(line);
        }   
        
        // Keep track of the row number (j) and column number (i)
        i++;
        if (i%5 == 0) {
            i=0;
            j=j+1;
        }

    }
    
    outFile = fopen("report.txt", "w");
    
    int sum1=0,sum2=0,sum3=0;
    for (int idx=0;idx<j;idx++) {
        
        sum1=sum1+score1[idx];
        sum2=sum2+score2[idx];
        sum3=sum3+score3[idx];
        
        scoreAvg[idx] = (score1[idx]+score2[idx]+score3[idx])/3.0;
        
        if (scoreAvg[idx] >= 90.0) {
            letterGrade[idx] = 'A';
        } else {
            if (scoreAvg[idx] >= 80.0) {
                letterGrade[idx] = 'B';
            } else {
                if (scoreAvg[idx] >= 70.0) {
                    letterGrade[idx] = 'C';
                } else {
                    if (scoreAvg[idx] >= 60.0) {
                        letterGrade[idx] = 'D';
                    } else {
                        letterGrade[idx] = 'F';
                    }
                }
            }
        }
        
        fprintf(stdout,"%s\t%s\t%d\t%d\t%d\t%c\n",
                lastName[idx],firstName[idx],score1[idx],score2[idx],
                score3[idx],letterGrade[idx]);
        fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%c\n",
                lastName[idx],firstName[idx],score1[idx],score2[idx],
                score3[idx],letterGrade[idx]);
    }
    
    fprintf(stdout,"\n");
    fprintf(outFile,"\n");
    
    test1Average = (double)sum1/j;
    test2Average = (double)sum2/j;
    test3Average = (double)sum3/j;
    
    fprintf(stdout,"Averages: midterm1 %4.2f, midterm2 %4.2f, final %4.2f\n",
            test1Average,test2Average,test3Average);
    fprintf(outFile,"Averages: midterm1 %4.2f, midterm2 %4.2f, final %4.2f\n",
            test1Average,test2Average,test3Average);
    
    fclose(inFile);
    fclose(outFile);
    
    
    return (EXIT_SUCCESS);
}

