/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 22, 2021, 12:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

void printBytes(int* arr, int n) {
    
    for (int i = 0; i<n; i++) {
        printf("%08x ",arr[i]);
    }
}

void printBytesVoidPointer(void* arr, int n) {
    
    for (int i = 0; i<n; i++) {
        printf("%02x ",((char*)arr)[i]);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int arr[] = {16, 31, 32, 65 }; // 16 bytes total = 4 x 4 bytes
    printBytes(arr, 4);
    printf("\n\n");
    
    long long arr_long[] = {16, 31, 32, 65}; // 32 bytes total = 4 x 8 bytes
    printBytes(arr_long, 4);
    
    printf("\n\n");
    
    printBytesVoidPointer(arr_long, 4*sizeof(long long));
    printf("\n\n");
    
    char name[] = "John";
    printBytesVoidPointer(name, 4*sizeof(char));
    
    printf("\n\n");
    printBytesVoidPointer(arr, 4*sizeof(int));
    
    

    return (EXIT_SUCCESS);
}

