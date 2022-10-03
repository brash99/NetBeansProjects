/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *
 */

#define REALTYPE double

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gplot_theory(REALTYPE x[], REALTYPE y[], REALTYPE ytheory[], int Npoints, char title[], char xlabel[], char ylabel[], char legendlabel[], char theorylabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_theory ...\n");
    
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
    
    char this_legendlabel[150];
    strcpy(this_legendlabel,"plot 'gnuplotData' using 1:2 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with points linestyle 1, 'gnuplotData' using 1:3 title '");
    strcat(this_legendlabel,theorylabel);
    strcat(this_legendlabel,"' with lines linestyle 2\n");
    
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
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linewidth 2\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints; i++) {
        fprintf(gnudata, "%g %g %g\n", x[i], y[i], ytheory[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata);
    
}

void gplot_theoryline(REALTYPE x[], REALTYPE y[], REALTYPE ytheory[], int Npoints, char title[], char xlabel[], char ylabel[], char legendlabel[], char theorylabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_theoryline ...\n");
    
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
    
    char this_legendlabel[150];
    strcpy(this_legendlabel,"plot 'gnuplotData' using 1:2 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with linespoints linestyle 1, 'gnuplotData' using 1:3 title '");
    strcat(this_legendlabel,theorylabel);
    strcat(this_legendlabel,"' with lines linestyle 2\n");
    
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
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linewidth 2\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints; i++) {
        fprintf(gnudata, "%g %g %g\n", x[i], y[i], ytheory[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata);
    
}

void gplot_twosets(REALTYPE x1[], REALTYPE y1[], int Npoints1, REALTYPE x2[], REALTYPE y2[], int Npoints2, char title[], char xlabel[], char ylabel[], char legendlabel[], char theorylabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_twosets ...\n");
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata1 = fopen("gnuplotData1", "w");
    FILE *gnudata2 = fopen("gnuplotData2", "w");
    
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
    
    char this_legendlabel[150];
    strcpy(this_legendlabel,"plot 'gnuplotData1' using 1:2 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with points linestyle 1, 'gnuplotData2' using 1:2 title '");
    strcat(this_legendlabel,theorylabel);
    strcat(this_legendlabel,"' with points linestyle 2\n");
    
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
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linetype 1 linewidth 2 pointtype 8 pointsize 1.5\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints1; i++) {
        fprintf(gnudata1, "%g %g\n", x1[i], y1[i]);
    }
    for (int i = 0; i < Npoints2; i++) {
        fprintf(gnudata1, "%g %g\n", x2[i], y2[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata1);
    fflush(gnudata2);
    
}

void gplot_twosetsline(REALTYPE x1[], REALTYPE y1[], int Npoints1, REALTYPE x2[], REALTYPE y2[], int Npoints2, char title[], char xlabel[], char ylabel[], char legendlabel[], char theorylabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_twosetsline ...\n");
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata1 = fopen("gnuplotData1", "w");
    FILE *gnudata2 = fopen("gnuplotData2", "w");
    
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
    
    char this_legendlabel[150];
    strcpy(this_legendlabel,"plot 'gnuplotData1' using 1:2 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with linespoints linestyle 1, 'gnuplotData2' using 1:2 title '");
    strcat(this_legendlabel,theorylabel);
    strcat(this_legendlabel,"' with linespoints linestyle 2\n");
    
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
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linetype 1 linewidth 2 pointtype 8 pointsize 1.5\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints1; i++) {
        fprintf(gnudata1, "%g %g\n", x1[i], y1[i]);
    }
    for (int i = 0; i < Npoints2; i++) {
        fprintf(gnudata2, "%g %g\n", x2[i], y2[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata1);
    fflush(gnudata2);
    
}

void gplot_twosets_loglog(REALTYPE x1[], REALTYPE y1[], int Npoints1, REALTYPE x2[], REALTYPE y2[], int Npoints2, char title[], char xlabel[], char ylabel[], char legendlabel[], char theorylabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_twosets ...\n");
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata1 = fopen("gnuplotData1", "w");
    FILE *gnudata2 = fopen("gnuplotData2", "w");
    
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
    
    char this_legendlabel[150];
    strcpy(this_legendlabel,"plot 'gnuplotData1' using 1:2 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with points linestyle 1, 'gnuplotData2' using 1:2 title '");
    strcat(this_legendlabel,theorylabel);
    strcat(this_legendlabel,"' with points linestyle 2\n");
    
    /* Set title, and axis labels */
    fprintf(gnuplot, "set key outside\n");
    fprintf(gnuplot, "set log xy\n");
    fprintf(gnuplot, "set key font 'Arial,10'\n");
    fprintf(gnuplot, "set tics font 'Arial,12'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, this_title);
    fprintf(gnuplot, this_xlabel);
    fprintf(gnuplot, this_ylabel);
    
    /* plot command - plot the data as points, and the prediction as a solid line (green)*/
    
    fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5\n");
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linetype 1 linewidth 2 pointtype 8 pointsize 1.5\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints1; i++) {
        fprintf(gnudata1, "%g %g\n", x1[i], y1[i]);
    }
    for (int i = 0; i < Npoints2; i++) {
        fprintf(gnudata1, "%g %g\n", x2[i], y2[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata1);
    fflush(gnudata2);
    
}

void gplot_twosetsline_loglog(REALTYPE x1[], REALTYPE y1[], int Npoints1, REALTYPE x2[], REALTYPE y2[], int Npoints2, char title[], char xlabel[], char ylabel[], char legendlabel[], char theorylabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_twosetsline ...\n");
    
    FILE *gnuplot = fopen("gnuplotScript", "w");
    FILE *gnudata1 = fopen("gnuplotData1", "w");
    FILE *gnudata2 = fopen("gnuplotData2", "w");
    
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
    
    char this_legendlabel[150];
    strcpy(this_legendlabel,"plot 'gnuplotData1' using 1:2 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"' with linespoints linestyle 1, 'gnuplotData2' using 1:2 title '");
    strcat(this_legendlabel,theorylabel);
    strcat(this_legendlabel,"' with linespoints linestyle 2\n");
    
    /* Set title, and axis labels */
    fprintf(gnuplot, "set key outside\n");
    fprintf(gnuplot, "set log xy\n");
    fprintf(gnuplot, "set key font 'Arial,10'\n");
    fprintf(gnuplot, "set tics font 'Arial,12'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, this_title);
    fprintf(gnuplot, this_xlabel);
    fprintf(gnuplot, this_ylabel);
    
    /* plot command - plot the data as points, and the prediction as a solid line (green)*/
    
    fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5\n");
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linetype 1 linewidth 2 pointtype 8 pointsize 1.5\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints1; i++) {
        fprintf(gnudata1, "%g %g\n", x1[i], y1[i]);
    }
    for (int i = 0; i < Npoints2; i++) {
        fprintf(gnudata2, "%g %g\n", x2[i], y2[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata1);
    fflush(gnudata2);
    
}

void gplot_hist_basic(REALTYPE x[], int Npoints, int binwidth, int binstart, char title[], char xlabel[], char legendlabel[], char system_type[]) {
    
    /* now that we have the data, create/open a GNUPlot script and data file for later plotting */
    
    printf ("In gplot_hist_basic ...\n");
    
    FILE *gnuplot = fopen("gnuplotHistScript", "w");
    FILE *gnudata = fopen("gnuplotHistData", "w");
    
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
    
    char this_legendlabel[150];
    
    strcpy(this_legendlabel,"plot 'gnuplotHistData' i 0 @hist ls 1 title '");
    strcat(this_legendlabel,legendlabel);
    strcat(this_legendlabel,"'\n");
    
    /* Set title, and axis labels */
    fprintf(gnuplot, "binwidth = %d\n",binwidth);
    fprintf(gnuplot, "binstart = %d\n",binstart);
    fprintf(gnuplot, "set key outside\n");
    fprintf(gnuplot, "set key font 'Arial,10'\n");
    fprintf(gnuplot, "set tics font 'Arial,12'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set boxwidth 0.90*binwidth\n");
    fprintf(gnuplot, "set style fill solid 0.5\n");
    fprintf(gnuplot, "hist = 'u (binwidth*(floor(($1-binstart)/binwidth)+0.5)+binstart):(1.0) smooth freq w boxes'\n");
    fprintf(gnuplot, this_title);
    fprintf(gnuplot, this_xlabel);
    
    /* plot command - plot the data as points, and the prediction as a solid line (green)*/
    
    fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5\n");
    fprintf(gnuplot, "set style line 2 linecolor rgb '#8b0000' linewidth 2\n");
    fprintf(gnuplot, "set macro\n");
    fprintf(gnuplot, this_legendlabel);
    
    /* write the data to be plotted to a file*/
    for (int i = 0; i < Npoints; i++) {
        fprintf(gnudata, "%g\n", x[i]);
    }
    
    /* cleanup */
    fflush(gnuplot);
    fflush(gnudata);
    
}

