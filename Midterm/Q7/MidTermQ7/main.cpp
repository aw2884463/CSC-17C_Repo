/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 17, 2022, 3:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
/*
 * 
 */

int findMatchCount(int []);

int main(int argc, char** argv) {
    
    //Rand seed.
    srand(static_cast<unsigned int>(std::time(nullptr)));
    //Declare Variables.
    int hand[4];
    int runs = 100000;
    float prob = 0;
    int pair = 0;
    int fourKind = 0;
    int threeKind = 0;
    int twoPair = 0;
    
    
    //Simulation
    for(int i = 0;i < runs;i++) {
        for(int i = 0;i < 4;i++) {
            hand[i] = rand() % 13;
        }
        if (findMatchCount(hand) == 2) {
            pair++;
        }
        if (findMatchCount(hand) == 3) {
            threeKind++;
        }
        if (findMatchCount(hand) == 4) {
            fourKind++;
        }
        if (findMatchCount(hand) == 72) {
            twoPair++;
        }
    }
    
    //Output results
    prob = (float) pair / runs;
    cout << fixed << setprecision(5) << prob << "% of 1 pair." << endl;
    prob = (float) fourKind / runs;
    cout << fixed << setprecision(6) <<  prob << "% of four of a kind." << endl;
    prob = (float) threeKind / runs;
    cout << fixed << setprecision(6) <<  prob << "% of three of a kind." << endl;
    prob = (float) twoPair / runs;
    cout << fixed << setprecision(6) <<  prob << "% of 2 pair." << endl;
    return 0;
}


int findMatchCount(int hand[]) {
    int count = 0;
    int highCount = 0;
    for(int i = 0;i < 13;i++) {
        for(int j = 0;j < 4;j++) {           
            if(hand[j] == i) {
                count++;
            }
        }
        if(count == highCount && count == 2) { //Found two pairs.
            return 72;
        }
        if(count > highCount) { //Keeps track of highest mode.
            highCount = count;
        }
        count = 0;
    }
    return highCount;
}