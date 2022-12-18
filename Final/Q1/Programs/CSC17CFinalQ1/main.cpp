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
#include <string>
#include <ctime>
#include <iostream>
#include <list>
#include <iterator>
#include <map>


#include "Node.h"

using namespace std;

/*
 * 
 */

int NumHash(string hashString);
int char2int(char c);
string makeInitial();


int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0))); 
    int size = 512;
    string *inits = new string[size];
    list<string> table[size];
    map<int, int> collisions;
    
   for(int i = 0;i < size;i++) { 
       inits[i] = makeInitial();
       //cout << inits[i] << " " << NumHash(inits[i]) << endl; ///@Debug
   }
    for(int i = 0;i < size;i++) {
        int hash = NumHash(inits[i]) % size;
        collisions[hash]++;
        table[hash].push_back(inits[i]);
    }
    for(int i = 0;i < size;i++) {    
        for(list<string>::iterator it = table[i].begin();it != table[i].end();it++) {
            //cout << *it  << " " << i << endl; ///@Debug
        }
    }
    int cCount[11] = {0};
    int max = 0;
    for (map<int, int>::iterator itr = collisions.begin(); itr != collisions.end(); ++itr) {
        cCount[itr->second]++;
    }
    cout << "There was " << size - collisions.size() << " cells with 0 elements." << endl;
    for(int i = 1;i <= 10;i++) {
        cout << "There was " << cCount[i] << " cells with " << i << " elements." << endl;
         if(cCount[i] != 0) {
            max = i;
        }
    }
    cout << "The max number of collisions was with " << max << " elements."<< endl;
    return 0;
}
string makeInitial() {
    
    string temp;
    for(int i = 0;i < 3;i++) {
        int r = rand() % 26 + 65;
        //cout << r << " "; ///@Debug
        temp += r;
        
    }
    return temp;
}

int NumHash(string hashString) {
    
    int hash = 0;
    
    for(int i = 0;i < hashString.length();i++) {
        if(i == 0) {
           hash += char2int(hashString[i]) * 100;
        }
        else if(i == 1) {
           hash += char2int(hashString[i]) * 10; 
        }
        else {
            hash += char2int(hashString[i]);
        }
    }
    return hash;
}

int char2int(char c) {
    
    
    if(c == 'A' || c == 'B' || c == 'C') {
        return 2;
    }
    else if (c == 'D' || c == 'E' || c == 'F') {
        return 3;
    }
    else if (c == 'G' || c == 'H' || c == 'I') {
        return 4;
    }
    else if (c == 'J' || c == 'K' || c == 'L') {
        return 5;
    }
    else if (c == 'M' || c == 'N' || c == 'O') {
        return 6;
    }
    else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') {
        return 7;
    }
    else if (c == 'T' || c == 'U' || c == 'V') {
        return 8;
    }
    else {
        return 9;
    }
}

