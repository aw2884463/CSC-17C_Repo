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

void battleplayer::placeShips() {
    
   set<tuple<int,int,bool>>::iterator it;
   for(int i = 2;i <= 5;i++) {
       it = ships.find(tuple<int,int,bool>(1,i,false));
       tuple<int,int,bool> temp = *it;
       cout << get<0>(temp) << " " << get<1>(temp)<< " " << get<2>(temp) << endl;
   }
    
}

