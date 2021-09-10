/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 7, 2021, 9:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BITS 32
#define REALTYPE float
#define EXPONENT 8
#define MANTISSA 23
#define EOFFSET 127

/* #define BITS 64
#define REALTYPE double
#define EXPONENT 11
#define MANTISSA 52
#define EOFFSET 1023 */

/*
 * 
 */

int main(int argc, char** argv) {
    
    
    REALTYPE x = 123.456;
    
    // the binary representation of a floating point number (32 bits) is:
    // 
    // seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
    //
    // where s is the sign bit, eeeeeeee are the bits of the exponent, and
    // mmmmmmmmmmmmmmmmmmmmmmm are the bits of the mantissa.
    //
    // The binary scientific notation representation of a float is:
    //
    // x = (-1)^s * 1.mmmmmmmmmmmmmmmmmmmmmmm * 2^(eeeeeeee-127)
    
    int s;
    int exponent_bits[EXPONENT];
    int mantissa_bits[MANTISSA];
    
    for (int i=0; i<EXPONENT; i++) {
        exponent_bits[i]=0;
    }
    for (int i=0; i<MANTISSA; i++) {
        mantissa_bits[i]=0;
    }
    
    if (x<0) {
        s = 1;
    } else {
        s = 0;
    }
    
    int exponent;
    REALTYPE xabs = x/pow(-1,s);
    
    for (int ie = -EOFFSET+1; ie<=EOFFSET; ie++) {
        if (xabs >= pow(2,ie)) {
            exponent = ie;
        }
    }
    
    printf("sign = %d, exponent = %d\n",s,exponent);
    
    REALTYPE mantissa = xabs/pow(2,exponent);
    
    printf("mantissa (decimal) = %g\n",mantissa);
    
    int ee = exponent+EOFFSET;
    REALTYPE mm = mantissa-1;
    
    int bitcounter = EXPONENT -1;
    while (ee>0) {
        exponent_bits[EXPONENT-1-bitcounter] = ee%2;
        //printf("%d %d %d\n",bitcounter,ee,exponent_bits[7-bitcounter]);
        ee = ee/2;
        bitcounter--;
    }
    
    printf("\n");
    printf("%d-Bit binary Representation of %g:\n",BITS,x);
    printf("\n");
    printf("%d|",s);
    
    for (int ie = 0; ie<EXPONENT; ie++) {
        printf("%d",exponent_bits[EXPONENT-1-ie]);
    }
    printf("|");
  
    
    for (bitcounter=MANTISSA-1;bitcounter>=0;bitcounter--) {
         
        // Multiply n by 2 to check it 1 or 0
        REALTYPE b = mm * 2;
        if (b >= 1) {
            mantissa_bits[bitcounter] = 1;
            mm = b - 1;
        } else {
            mantissa_bits[bitcounter] = 0;
            mm = b;
        }
        //printf("%g %d %d\n",mm,bitcounter,mantissa_bits[bitcounter]);
        
    }
    
    for (int ie = 0; ie<MANTISSA; ie++) {
        printf("%d",mantissa_bits[MANTISSA-1-ie]);
    }
    
    printf("\n");

    return (EXIT_SUCCESS);
}


