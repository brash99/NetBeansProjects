/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 1, 2022, 10:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 80

/*
 * 
 */
int main(int argc, char** argv) {
    
    const unsigned int nMax = 1000;
    
    FILE* inFile = NULL; //This variable will be a "pointer" to the input file
    FILE* outFile = NULL; //This variable will be a "pointer" to the output file
    
    char lastName[nMax][LINE], firstName[nMax][LINE];
    int score1[nMax],score2[nMax],score3[nMax];
    char letterGrade[nMax];
    double scoreAvg[nMax];
    double test1Average,test2Average,test3Average;
    
    char gradeList[5] = {'A','B','C','D','F'}; // Define a char array to hold
                                               // all possible letter grades
    
    int filetype=2;
    
    /* Get the filename from the user */  
    char filename[LINE];
    //printf("Enter the filename:\n");
    
    //gets(filename);
    // Note:  gets will work, and you will see it in a lot of
    // code, but it has been deprecated in C11, so we probably should not use it
    // anymore.
   
    
    //scanf("%s", filename);
    //printf("Filename = %s\n",filename);
    
    /* Open the file for reading */
    //inFile = fopen(filename, "r");
    
    if (filetype==1) {
        inFile = fopen("StudentInfo.csv", "r");
    } else {
        inFile = fopen("StudentInfo.tsv", "r");
    }
    
    if (inFile == NULL) {
        printf("Error:  Could not open file:  %s\n",filename);
        exit(-1);
    } else {
        printf("File opened successfully ...... \n\n");
    }
    
    char line[LINE]; //char array to hold each "line" read from the file
    
    int j=0;  // This will hold the row number
    
    //while (EOF != fscanf(inFile, "%s", line)) {
    while (fgets(line,sizeof line, inFile) != NULL) {
        
        // Read and parse line, with commas as separators
        
        if (filetype == 1) {
            sscanf(line,"%[^,],%[^,],%d,%d,%d\n",lastName[j],firstName[j],
                    &score1[j],&score2[j],&score3[j]);
        } else {
            sscanf(line,"%s\t%s\t%d\t%d\t%d\n",lastName[j],firstName[j],
                    &score1[j],&score2[j],&score3[j]);  
        }
        
        j++;
        
    }
    
    outFile = fopen("report.txt", "w");
    
    int sum1=0,sum2=0,sum3=0;
    for (int idx=0;idx<j;idx++) {
        
        sum1=sum1+score1[idx];
        sum2=sum2+score2[idx];
        sum3=sum3+score3[idx];
        
        scoreAvg[idx] = (score1[idx]+score2[idx]+score3[idx])/3.0;
        
        int glIdx = 9-(int)scoreAvg[idx]/10; // calculate gradeList index
        if (glIdx >= 4) glIdx=4;             // lump all F grades together
        letterGrade[idx]=gradeList[glIdx];   // assign the correct letter grade
        
        if (filetype == 1) {
            fprintf(stdout,"%s,%s,%d,%d,%d,%c\n",lastName[idx],firstName[idx],
                    score1[idx],score2[idx],score3[idx],letterGrade[idx]);
            fprintf(outFile,"%s,%s,%d,%d,%d,%c\n",lastName[idx],firstName[idx],
                    score1[idx],score2[idx],score3[idx],letterGrade[idx]);
        } else {
            fprintf(stdout,"%s\t%s\t%d\t%d\t%d\t%c\n",lastName[idx],
                    firstName[idx],score1[idx],score2[idx],score3[idx],
                    letterGrade[idx]);
            fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%c\n",lastName[idx],
                    firstName[idx],score1[idx],score2[idx],score3[idx],
                    letterGrade[idx]);
        }
        
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
    
}

