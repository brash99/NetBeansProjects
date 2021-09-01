/*
 * A demonstration program to illustrate the primitive data types in C
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on July 30, 2021, 10:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

/*
 * 
 */

void convert_long_to_bin(unsigned long n)
  {
    unsigned long i;
    printf("0");
    for (i = 1UL << (sizeof(n)*CHAR_BIT-1); i > 0; i = i / 2) {
      if((n & i) != 0) {
        printf("1");
      }
      else {
        printf("0");
      }
    }
  }

int main(int argc, char** argv) {
    
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
    
    printf("Storage size for float : %lu \n", sizeof(float));
    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
    printf("Precision value for float: %d\n", FLT_DIG );
    printf("Precision value for double: %d\n", DBL_DIG );
    
    printf("\n");
    unsigned long decimal_number = (unsigned long)9223372036854775807;
    convert_long_to_bin(decimal_number);
    printf("\n\n");
    
    decimal_number = (unsigned long)18446744073709551615;
    convert_long_to_bin(decimal_number);
    printf("\n\n");

    return (EXIT_SUCCESS);
}

