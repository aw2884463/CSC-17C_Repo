/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   battleplayer.cpp
 * Author: Austin
 * 
 * Created on October 26, 2022, 1:12 PM
 */
#include "battleplayer.h"

battleplayer::battleplayer() {
    
    for(int i =0;i < 5;i++) {
        shipStats[i] = 0;
    }
}

battleplayer::battleplayer(const battleplayer& orig) {
}

battleplayer::~battleplayer() {
}

