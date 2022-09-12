/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 4, 2022, 11:09 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * A test program to illustrate the use of C format specifiers (for output).
 */
int main(int argc, char** argv) {
    
    char a = 'C';
    // char b[7] = "BCDEFGH"; <- No! don't do this!!!
    char b[] = "BCDEFGH";
    printf("%c\n",a);
    printf("%s\n",b);
    printf("\n");
    
    signed int n = -1234; // the keyword 'signed' is not necessary here
    unsigned int m = 1234;
    printf("%d\n",n);
    printf("%u\n",m);
    printf("\n");
    
    float x = -1234567.0; // seven significant figures
    float xs = -123456.0; // six significant figures
    float xl = 9429732343.92173497; // has way more precision than float can handle
    printf("%lf\n",x);
    printf("%lf\n",xl); 
    printf("%e\n",x);
    printf("%E\n",x);
    printf("%g\n",x); // should print in sci. notation, as x has seven sig. figs.
    printf("%G\n",x);
    printf("%g\n",xs); // should print in decimal, as xs has six sig. figs.
    printf("%G\n",xs);
    printf("\n");
    
    // the keywords 'signed' and 'int' are not necessary in these next six statements!
    signed short int nn = -234; 
    unsigned short int mm = 231;
    
    signed long int nnn = -9826475947;
    unsigned long int mmm = 2034982382;
    
    signed long long int nnnn = -293847237239487;
    unsigned long long int mmmm = 928343942398723;
    
    printf("%hi\n",nn);
    printf("%hu\n",mm);
    printf("\n");
    
    printf("%li\n",nnn);
    printf("%lu\n",mmm);
    printf("\n");
    
    printf("%lli\n",nnnn);
    printf("%llu\n",mmmm);
    printf("\n");
    
    double xx = -9429732343.92173497; // This number has more sig. figs. than double can handle
    long double xxx = -9429732343.92173497; // looks like a long double, but really isn't!!
    long double xxxx = -9429732343.92173497L; // Need to add L to the end to get long double precision!!

    printf("%lf\n",xx);
    printf("%Lf\n",xxx);
    printf("%Lf\n",xxxx);
    printf("\n");
    
    //---------------------------- Now, let's look at the extra qualifiers ------------------
    
    // Illustrate field width with integers
    int i=45, j=145, k=-145, l=2145;
    printf("%3d\n",i); // Adds a pre-space, since i is only two digits
    printf("%3d\n",j); // j is three digits, field is three digits ... perfect:)
    printf("%3d\n",k); // k is three significant digits - minus sign does not count!!
    printf("%3d\n",l); // l is four digits ... the "3" indicates MINIMUM field width!!
    printf("\n");
    
    // Illustrate precision for floats/doubles
    float xp = 12.345678;
    float yp = 12.3456789;
    float zp = 12.34567;
    float tp = 123.45678;
    printf("%9.6f\n",xp); // xp has 6 decimal places
    printf("%9.6f\n",yp); // yp has 7 decimal places, so it will get ROUNDED to six
    printf("%9.6f\n",zp); // zp has 5 decimal places, so extra zero will be added at the end
    printf("%9.6f\n",tp); // tp has 5 decimal places, so expect extra zero will be added.
                          // this will make the number be 123.345670, which has 10 characters
                          // in its field.  This is okay, since the "9" in 9.6 specified a
                          // MINIMUM field width. However, what we see instead is 123.345673???
                          // This is because 123.245670 exceeds the precision limit of float!!!
                          // A great example of why we should just use double!!!
    printf("\n");
    
    double xpd = 12.345678;
    double ypd = 12.3456789;
    double zpd = 12.34567;
    double tpd = 123.45678;
    printf("%9.6f\n",xpd); // xpd has 6 decimal places
    printf("%9.6f\n",ypd); // ypd has 7 decimal places, so it will get ROUNDED to six
    printf("%9.6f\n",zpd); // zpd has 5 decimal places, so extra zero will be added at the end
    printf("%9.6f\n",tpd); // now, indeed we get 123.345670, as expected!!!
    printf("\n");
    
    //Illustrate alignment with int/float/double
    int ial = 1234;
    printf("%9d|\n",ial);
    printf("%-9d|\n",ial);
    printf("\n");
    
    float xal = 1.23;
    printf("%9.2f|\n",xal);
    printf("%-9.2f|\n",xal);
    printf("\n");
    
    //Illustrate alignment with + sign in format specifier
    //
    //TL;DR if you want positive/negative numbers to be aligned, either use
    //      an explicit + sign in the format specifier, or take the minus
    //      sign into account in the field width specification.
    //
    float xpp = 12.345678;
    float xmm = -12.345678;
    printf("%9.6f\n",xpp); //number width = 9
    printf("%9.6f\n",xmm); //number width = 9, plus minus sign => 10 characters
    printf("%+9.6f\n",xpp); //number width = 9, plus explicit + sign => 10 characters
    printf("%+9.6f\n",xmm); //number width = 9, plus minus sign => 10 characters
    printf("%10.6f\n",xpp); //number width = 9, field width = 10 => 10 characters
    printf("%10.6f\n",xmm); //number width = 9, plus minus sign => 10 characters
    printf("\n");
    
    int ipp = 123456789;
    int imm = -123456789;
    printf("%9d\n",ipp); //number width = 9
    printf("%9d\n",imm); //number width = 9, plus minus sign => 10 characters
    printf("%+9d\n",ipp); //number width = 9, plus explicit + sign => 10 characters
    printf("%+9d\n",imm); //number width = 9, plus minus sign => 10 characters
    printf("%10d\n",ipp); //number width = 9, field width = 10 => 10 characters
    printf("%10d\n",imm); //number width = 9, plus minus sign => 10 characters
    printf("\n");
    
    //Illustrate zero-padding
    //
    float xpad = 1.234567;
    printf("%012.6f\n",xpad); //field width = 12, pad with leading zeroes
    //printf("%-012.6f\n",xpad); //0 is ignored when minus sign is present!!
    printf("\n");
    
    int ipad = 713;
    int ipadm = -713;
    printf("%04d\n",ipad);
    printf("%04d\n",ipadm); //in padding negative numbers with zeros, the minus sign IS included in field width
    printf("%08d\n",ipad);
    printf("%08d\n",ipadm);
    printf("%+08d\n",ipad);
    printf("%+08d\n",ipadm);
    //printf("%-08d\n",ipad); //again, 0 is ignored when minus sign is present
    //printf("%-08d\n",ipadm);
    printf("\n");
    
    //Illustrate alignment with strings (char arrays)
    char sss[] = "Hello World"; //11 character string
    printf("Here is the |%s| string.\n",sss);
    printf("Here is the |%20s| string.\n",sss); //Field width = 20, right aligned
    printf("Here is the |%-20s| string.\n",sss); //Field width = 20, left aligned
    printf("Here is the |%20.5s| string.\n",sss); //Field width = 20, first 5 characters, right aligned
    printf("Here is the |%-20.5s| string.\n",sss); //Field width = 20, first 5 characters, left aligned
    printf("\n");
  
    
    return (EXIT_SUCCESS);
}

