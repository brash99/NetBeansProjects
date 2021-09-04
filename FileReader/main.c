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

#define LINE 80

/*
 *  Program to read data from a file and process
 * 
 *  The data file has many lines, of the form:
 * LastName FirstName   Score1 Score2 Score3
 */
int main(int argc, char** argv) {
    
    /* Define necessary variables */
    
    const unsigned int nMax = 1000;
    
    FILE* inFile = NULL; //This variable will be a "pointer" to the file
    
    char lastName[nMax][LINE], firstName[nMax][LINE];
    int score1[nMax],score2[nMax],score3[nMax];
    
    /* Get the filename from the user */  
    char filename[LINE];
    printf("Enter the filename:\n");
    
    //gets(filename);
    // Note:  gets will work, and you will see it in a lot of
    // code, but it has been deprecated in C11, so we probably should not use it
    // anymore.
    // 
    // Instead, we will use scanf.  The format code is weird!
    // Explanation : Here, [] is the scanset character. ^\n tells to take 
    // input until newline doesn’t get encountered. Then, with this %*c, it 
    // reads newline character and here used * indicates that this 
    // newline character is discarded.
    
    //scanf("%[^\n]%*c", filename);
    //printf("Filename = %s",filename);
    
    /* Open the file for reading */
    //inFile = fopen(filename, "r");
    inFile = fopen("StudentInfo.tsv", "r");
    
    if (inFile == NULL) {
        printf("Error:  Could not open file:  %s\n",filename);
        exit(-1);
    } else {
        printf("File opened successfully ... \n");
    }
    
    char line[LINE]; //char array to hold each "line" read from the file
    
    int i = 0, j=0;  // These will hold the column number and row number
    
    while (EOF != fscanf(inFile, "%s", line)) {
        
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
        
        if (i==0) {
            strcpy(lastName[j], line);
        }
        if (i==1) {
            strcpy(firstName[j], line);
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
    
    double scoreAvg[nMax];
    for (int idx=0;idx<j;idx++) {
        scoreAvg[idx]=(score1[idx]+score2[idx]+score3[idx])/3.0;
        printf("%s %s %d:%d:%d = %7.2f\n",lastName[idx],firstName[idx],score1[idx],score2[idx],score3[idx],scoreAvg[idx]);
    }
    
    return (EXIT_SUCCESS);
}

