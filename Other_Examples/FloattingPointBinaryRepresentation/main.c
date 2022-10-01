/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 4, 2021, 2:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */

int main(int argc, char** argv) {
    
    
    float x = 0.1;
    
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
    int exponent_bits[8];
    int mantissa_bits[23];
    
    for (int i=0; i<8; i++) {
        exponent_bits[i]=0;
    }
    for (int i=0; i<23; i++) {
        mantissa_bits[i]=0;
    }
    
    if (x<0) {
        s = 1;
    } else {
        s = 0;
    }
    
    int exponent;
    float xabs = x/pow(-1,s);
    
    for (int ie = -126; ie<=127; ie++) {
        if (xabs >= pow(2,ie)) {
            exponent = ie;
        }
    }
    
    printf("sign = %d, exponent = %d\n",s,exponent);
    
    float mantissa = xabs/pow(2,exponent);
    
    printf("mantissa (decimal) = %g\n",mantissa);
    
    int ee = exponent+127;
    double mm = mantissa-1;
    
    int bitcounter = 7;
    while (ee>0) {
        exponent_bits[7-bitcounter] = ee%2;
        //printf("%d %d %d\n",bitcounter,ee,exponent_bits[7-bitcounter]);
        ee = ee/2;
        bitcounter--;
    }
    
    printf("\n");
    printf("Binary Representation of %g:\n",x);
    printf("\n");
    printf("%d|",s);
    
    for (int ie = 0; ie<8; ie++) {
        printf("%d",exponent_bits[7-ie]);
    }
    printf("|");
  
    
    for (bitcounter=22;bitcounter>=0;bitcounter--) {
         
        // Multiply n by 2 to check it 1 or 0
        float b = mm * 2;
        if (b >= 1) {
            mantissa_bits[bitcounter] = 1;
            mm = b - 1;
        } else {
            mantissa_bits[bitcounter] = 0;
            mm = b;
        }
        //printf("%g %d %d\n",mm,bitcounter,mantissa_bits[bitcounter]);
        
    }
    
    for (int ie = 0; ie<23; ie++) {
        printf("%d",mantissa_bits[22-ie]);
    }
    
    printf("\n");

    return (EXIT_SUCCESS);
}

