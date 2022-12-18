/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on December 8, 2022, 4:13 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>



using namespace std;

/*
 * 
 */
float h(float,stack<bool>& count,stack<bool>& count2);
float g(float,stack<bool>& count,stack<bool>& count2);

int main(int argc, char** argv) {


    stack<bool> hcount;
    stack<bool> gcount;
    for(float i =-1.0;i <= 1.1;i+=0.1) {
        h(i,hcount,gcount);
        cout << "I:" << fixed << setprecision(2) << i << " - hcount: " << hcount.size()  << " - gcount: " << gcount.size() << endl;
        hcount.clear();
        for(int i =0;i < hcount.size();i++) {
            hcount.pop();
        }
        for(int i =0;i < gcount.size();i++) {
            gcount.pop();
        }
    }
    return 0;
}
float h(float angR,stack<bool>& hcount,stack<bool>& gcount){
    float tol=1e-6;
    hcount.push(1);
    if(angR>-tol&&angR<tol) return angR+angR*angR*angR/6;
    return 2*h(angR/2,hcount,gcount)*g(angR/2,hcount,gcount);
}
float g(float angR,stack<bool>& hcount,stack<bool>& gcount){
    float tol=1e-6;
    gcount.push(1);
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2,hcount,gcount);
    return 1+2*b*b;
}