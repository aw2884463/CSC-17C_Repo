/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   battleship.cpp
 * Author: Austin
 * 
 * Created on October 25, 2022, 9:50 AM
 */

#include "battleship.h"

battleship::battleship() {
    createMap();
}

battleship::battleship(const battleship& orig) {
}

battleship::~battleship() {
}

void battleship::createMap() {
    set<pair<int,int>>::iterator it = map1.begin();
    for(int i = 1;i < 8;i++) {
        for(int j = 1; j < 8;j++) {            
            map1.insert(make_pair(i, j));
        }
    }
    it = map2.begin();
    
    for(int i = 1;i < 8;i++) {
        for(int j = 1; j < 8;j++) {            
            map2.insert(make_pair(i, j));
        }
    }
}

void battleship::startGame() {
    
    
}

