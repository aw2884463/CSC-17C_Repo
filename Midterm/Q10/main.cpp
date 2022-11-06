/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 20, 2022, 9:50 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*  Recursive function for the equation*
 *  g(2x) = 2g(x)/1+g^2(x)
 */
float g2x(float x);
float gx(float x);
int main(int argc, char** argv) {
    
    for(float i =-1;i <= 1;i+=0.1) {
        cout << g2x(i) << endl;
    }
    return 0;
}

float g2x(float x) {
    
    float tol;
    tol = 1e-6f;
    
    if(abs(x) < tol)  {
        return x-x*x*x/6;
    }
    float term = g2x(x/2);
    return 2*term / (1 + term*term);
    
}



