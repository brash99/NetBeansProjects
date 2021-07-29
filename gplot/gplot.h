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

#ifndef GPLOT_H
#define GPLOT_H

#ifdef __cplusplus
extern "C" {
#endif

void gplot_basic(double [], double [], int , char [], char [], char [], char [], char []);
void gplot_errors(double [], double [], double [], int , char [], char [], char [], char [], char []);
        
#ifdef __cplusplus
}
#endif

#endif /* GPLOT_H */

