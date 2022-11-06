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
    giveMap();
    giveShips();
}

battleship::battleship(const battleship& orig) {
}

battleship::~battleship() {
}

//Creates the map
void battleship::createMap() {   
    for(int i = 1;i < 11;i++) {
        for(int j = 1; j < 11;j++) {            
            coords.insert(make_tuple(make_pair(i, j), false,make_pair(0,0)));
        }
    }
}

//Creates the ships
void battleship::createShips() {   
        for(int j = 2; j < 6;j++) {            
            ships.insert(make_tuple(1, j, false));
        }
//        set<tuple<int,int,bool>>::iterator it;
//        it = ships.find(tuple<int,int,bool>(1,2,false));
//         tuple<int,int,bool> temp = *it;
//        cout << get<2>(temp);
}

//Gives each player a map
void battleship::giveMap() { 
    
    for(int i = 0;i < 2;i++) {
        players[i].setpMap(coords);
    }
    
}

//Gives each player there ships.
void battleship::giveShips() {   
    for(int i = 0;i < 2;i++) {
      players[i].setShips(ships);
   }  
}

void battleship::gameLoop() {
    
}

void battleship::startGame() {
    
//    cout << "Welcome to my battleship game." << endl;
//    cout << "The rules are simple two players will get 4 ships and can place them anywhere on a 10x10 board." << endl;
//    cout << "Once the ships have been placed(no peeking), you can begin shooting missiles by calling coords." << endl;
//    cout << "Once all points on a ship have been hit the ships sinks." << endl;
//    cout << "When all of a players ships have been sunk that player looses." << endl;
//    cout << "Good luck." << endl << endl;
    players[0].placeShips();
    
    
    
}

