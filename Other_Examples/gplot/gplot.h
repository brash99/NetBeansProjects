/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gplot.h
 * Author: brash
 *
 * Created on July 29, 2021, 10:00 AM
 */

#define REALTYPE double

#ifndef GPLOT_H
#define GPLOT_H

#ifdef __cplusplus
extern "C" {
#endif

void gplot_basic(REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char []);
void gplot_basicline(REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char []);

void gplot_basic_loglog(REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char []);
void gplot_basicline_loglog(REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char []);

void gplot_errors(REALTYPE [], REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char []);
void gplot_errorsline(REALTYPE [], REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char []);

void gplot_theory(REALTYPE [], REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char [], char []);
void gplot_theoryline(REALTYPE [], REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char [], char []);

void gplot_twosets(REALTYPE [], REALTYPE [], int, REALTYPE[], REALTYPE [], int , char [], char [], char [], char [], char [], char []);
void gplot_twosetsline(REALTYPE [], REALTYPE [], int, REALTYPE[], REALTYPE [], int , char [], char [], char [], char [], char [], char []);

void gplot_twosets_loglog(REALTYPE [], REALTYPE [], int, REALTYPE[], REALTYPE [], int , char [], char [], char [], char [], char [], char []);
void gplot_twosetsline_loglog(REALTYPE [], REALTYPE [], int, REALTYPE[], REALTYPE [], int , char [], char [], char [], char [], char [], char []);

void gplot_errorstheory(REALTYPE [], REALTYPE [], REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char [], char []);
void gplot_errorstheoryline(REALTYPE [], REALTYPE [], REALTYPE [], REALTYPE [], int , char [], char [], char [], char [], char [], char []);

void gplot_hist_basic(REALTYPE [], int, int, int , char [], char [], char [], char []);

#ifdef __cplusplus
}
#endif

#endif /* GPLOT_H */

