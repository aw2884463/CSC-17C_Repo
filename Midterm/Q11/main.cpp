/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: austi
 *
 * Created on October 24, 2022, 12:57 PM
 */

//#include <cstdlib>
//#include <cmath>
//#include <iostream>
//using namespace std;
//
//
//float cx(float);
//float sx(float);
//
//int main(int argc, char** argv) {
//    
//    for(float i = 0;abs(i) <= atan(1);i+=0.1) {
//       cout << cx(i) << endl;
//    }   
//
//    return 0;
//}
//
//float cx(float x) {
//    
//    float tol;
//    tol = 1e-6f;
//    
//    if(abs(x) < tol)  {
//        return (1/x) + (x/6);
//    } 
//    return 0.5 *cx(x/2)*sx(x/2);
//}
//

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

float cx(float x);
float sx(float x);


int main(){


    for(float i = 0.1; abs(i) < atan(1); i+=0.1){
        cout << "S(" << i << ")= " << sx(i) << endl;
        cout << "C(" << i << ")= " << cx(i) << endl;
    }


}


float cx(float x) {
    
    float tol;
    tol = 1e-6f;
    
    if(abs(x) < tol)  {
        return (1/x) + (x/6);
    } 
    return 0.5 *cx(x/2)*sx(x/2);
}

float sx(float x) {
    
    float tol;
    tol = 1e-6f;
    
    if(abs(x) < tol)  {
        return 1 + (x*x/2);
    }
    float term1,term2;
    term1 = cx(x/2);
    term2 = sx(x/2);
    return (term1 * term1 * term2 * term2) / ((term1 * term1) - (term2 * term2));
}
