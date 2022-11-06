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
    createShips();
}

battleship::battleship(const battleship& orig) {
}

battleship::~battleship() {
}

void battleship::createMap() {   
    for(int i = 1;i < 11;i++) {
        for(int j = 1; j < 11;j++) {            
            coords.insert(make_pair(make_pair(i, j), false));
        }
    }
}

void battleship::createShips() {   
        for(int j = 2; j < 5;j++) {            
            ships.insert(make_pair(make_pair(1, j), false));
        }
}

void battleship::giveMap() {   
    
}

void battleship::giveShips() {   
    
}

void battleship::startGame() {
    
    
}

