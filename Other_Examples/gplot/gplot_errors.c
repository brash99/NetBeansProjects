/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define REALTYPE double

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gplot_errors(REALTYPE x[], REALTYPE y[], REALTYPE e[], int Npoints, 
        char title[], char xlabel[], char ylabel[], char legendlabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_errors ...\n");
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata = fopen("gnuplotData", "w");
    
    /* terminal type */
    if (strcmp(system_type,"Unix") == 0) {
        fprintf(gnuplot, "set terminal x11\n");
    } else {
        if (strcmp(system_type,"Windows") == 0) {
            fprintf(gnuplot, "set terminal qt\n");
        }
    }
    
    /* format title, xlabel, ylabel */
    char this_title[80];
    strcpy(this_title,"set title '");
    strcat(this_title,title);
    strcat(this_title,"' font 'Arial,20'\n");
    
    char this_xlabel[80];
    strcpy(this_xlabel,"set xlabel '");
    strcat(this_xlabel,xlabel);
    strcat(this_xlabel,"' font 'Arial,16'\n");
    
    char this_ylabel[80];
    strcpy(this_ylabel,"set ylabel '");
    strcat(this_ylabel,ylabel);
    strcat(this_ylabel,"' font 'Arial,16'\n");
    
    char this_legendlabel[100];
    strcpy(this_legendlabel,"plot 'gnuplotData' using 1:2:3 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with errorbars linestyle 1\n");
    
    /* Set title, and axis labels */
    fprintf(gnuplot, "set key outside\n");
    fprintf(gnuplot, "set key font 'Arial,10'\n");
    fprintf(gnuplot, "set tics font 'Arial,12'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, this_title);
    fprintf(gnuplot, this_xlabel);
    fprintf(gnuplot, this_ylabel);
    
    /* plot command - plot the data as points, and the prediction as a solid line (green)*/
    
    fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints; i++) {
        fprintf(gnudata, "%g %g %g\n", x[i], y[i], e[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata);
    
}

void gplot_errorsline(REALTYPE x[], REALTYPE y[], REALTYPE e[], int Npoints, 
        char title[], char xlabel[], char ylabel[], char legendlabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_errorsline ...\n");
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata = fopen("gnuplotData", "w");
    
    /* terminal type */
    if (strcmp(system_type,"Unix") == 0) {
        fprintf(gnuplot, "set terminal x11\n");
    } else {
        if (strcmp(system_type,"Windows") == 0) {
            fprintf(gnuplot, "set terminal qt\n");
        }
    }
    
    /* format title, xlabel, ylabel */
    char this_title[80];
    strcpy(this_title,"set title '");
    strcat(this_title,title);
    strcat(this_title,"' font 'Arial,20'\n");
    
    char this_xlabel[80];
    strcpy(this_xlabel,"set xlabel '");
    strcat(this_xlabel,xlabel);
    strcat(this_xlabel,"' font 'Arial,16'\n");
    
    char this_ylabel[80];
    strcpy(this_ylabel,"set ylabel '");
    strcat(this_ylabel,ylabel);
    strcat(this_ylabel,"' font 'Arial,16'\n");
    
    char this_legendlabel[100];
    strcpy(this_legendlabel,"plot 'gnuplotData' using 1:2:3 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with errorlines linestyle 1\n");
    
    /* Set title, and axis labels */
    fprintf(gnuplot, "set key outside\n");
    fprintf(gnuplot, "set key font 'Arial,10'\n");
    fprintf(gnuplot, "set tics font 'Arial,12'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, this_title);
    fprintf(gnuplot, this_xlabel);
    fprintf(gnuplot, this_ylabel);
    
    /* plot command - plot the data as points, and the prediction as a solid line (green)*/
    
    fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints; i++) {
        fprintf(gnudata, "%g %g %g\n", x[i], y[i], e[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata);
    
}
