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

/* #define BITS 32
#define REALTYPE float
#define EXPONENT 8
#define MANTISSA 23
#define EOFFSET 127 */

#define BITS 64
#define REALTYPE double
#define EXPONENT 11
#define MANTISSA 52
#define EOFFSET 1023

/*
 * 
 */

int* get_mantissa(REALTYPE);
int* get_exponent(REALTYPE);
int get_sign(REALTYPE);

void bit_print(REALTYPE);

int main(int argc, char** argv) {
    
    
    REALTYPE x = 12.3;
    
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
    
    printf("\n");
    printf("%d-Bit binary Representation of %g:\n",BITS,x);
    printf("\n");
    
    bit_print(x);

    return (EXIT_SUCCESS);
}

int get_sign(REALTYPE x) {
    int s;
    
    if (x<0) {
        s = 1;
    } else {
        s = 0;
    }
    
    return s;
}

int* get_exponent(REALTYPE x) {
    
    int s = get_sign(x);
    static int exponent_bits[EXPONENT];
    
    for (int i=0; i<EXPONENT; i++) {
        exponent_bits[i]=0;
    }
    
    if (x==0.0) {
        return exponent_bits;
    }
    
    int exponent;
    REALTYPE xabs = x/pow(-1,s);
    
    for (int ie = -EOFFSET+1; ie<=EOFFSET; ie++) {
        if (xabs >= pow(2,ie)) {
            exponent = ie;
        }
    }
    
    printf("sign = %d, exponent = %d\n",s,exponent);
    
    int ee = exponent+EOFFSET;
    
    int bitcounter = EXPONENT -1;
    while (ee>0) {
        exponent_bits[EXPONENT-1-bitcounter] = ee%2;
        //printf("%d %d %d\n",bitcounter,ee,exponent_bits[7-bitcounter]);
        ee = ee/2;
        bitcounter--;
    }
    
    return exponent_bits;
    
}

int* get_mantissa(REALTYPE x) {
    
    int s = get_sign(x);
    int exponent;
    REALTYPE xabs = x/pow(-1,s);
    static int mantissa_bits[MANTISSA];
    
    for (int i=0; i<MANTISSA; i++) {
        mantissa_bits[i]=0;
    }
    
    if (x==0.0) {
        return mantissa_bits;
    }
    
    for (int ie = -EOFFSET+1; ie<=EOFFSET; ie++) {
        if (xabs >= pow(2,ie)) {
            exponent = ie;
        }
    }
    
    REALTYPE mantissa = xabs/pow(2,exponent);
    REALTYPE mm = mantissa-1;
    
    printf("mantissa (decimal) = %g\n",mantissa);
    
    for (int bitcounter=MANTISSA-1;bitcounter>=0;bitcounter--) {
         
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
    
    return mantissa_bits;
    
}

void bit_print(REALTYPE x) {
    
    int s = get_sign(x);
    int* exponent_bits = get_exponent(x);
    int* mantissa_bits = get_mantissa(x);
    
    printf("\n(%d|",s);
    
    for (int ie = 0; ie<EXPONENT; ie++) {
        printf("%d",*(exponent_bits+(EXPONENT-1-ie)));
    }
    printf("|");
  
    for (int ie = 0; ie<MANTISSA; ie++) {
        printf("%d",mantissa_bits[MANTISSA-1-ie]);
    }
    
    printf(")\n");
    
    return;
     
};


