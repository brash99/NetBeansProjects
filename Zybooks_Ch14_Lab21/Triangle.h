/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Triangle.h
 * Author: 00465510
 *
 * Created on October 28, 2021, 7:19 PM
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
   private:
      double base;
      double height;
   
   public:
      void SetBase(double userBase);
      void SetHeight(double userHeight);
      double GetArea() const;
      void PrintInfo() const;
};


#endif /* TRIANGLE_H */

