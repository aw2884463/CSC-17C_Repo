/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 23, 2022, 2:02 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    srand(static_cast<unsigned int>(std::time(nullptr)));
    
    bitset<100> bset;
    int count = 0;
    int runs = 10000;
    int temp;
    int occ = 0;
    
    for(int j = 0;j < runs;j++) {
        for(int i = 0;i < 100;i++) {
            if(i <= 40) {
                bset[i] = 1;
            }
            else {
                bset[i] = 0;
            }
        }
        for(int i = 0;i < 5;i++) {
            temp = rand() % 100;
            if(bset[temp] == 1) {
               count++; 
            }
        }
        if(count == 5) {
            occ++;
        }
        count = 0;
    }
    cout << "The simulated probability = " << ((float) occ / runs) * 100 << "%" << endl;
    cout << "The calculated probability = " << pow((float)4/10,5) * 100 << "%";
    return 0;
}

