/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 23, 2022, 2:51 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

int RecurPwr(int x , int n);
int RecurPwrLn(int x , int n);

int main(int argc, char** argv) {
    
    cout << "Basic Recursive Power Function" << endl;
    for(int i =0; i < 12;i++) {
        cout << RecurPwr(2, i) << " ";
    }
    cout << endl;
    cout << "Optimized Recursive Power Function" << endl;
    for(int i =0; i < 12;i++) {
        cout << RecurPwrLn(2, i) << " ";
    }
    cout << endl;
    
    return 0;
}

int RecurPwr(int x , int n) {
    
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    return (x * RecurPwr(x, n - 1));
}

int RecurPwrLn(int x , int n) {
    
  if(n == 0) {
    return 1;
  }
  if(n == 1) {
    return x;
  }
  if (n%2 == 0) {
      
    return RecurPwrLn(x*x, n/2);
  }else{
        int a = RecurPwrLn(x ,(n-1)/2);
        return a * a * x;
  }   
}




