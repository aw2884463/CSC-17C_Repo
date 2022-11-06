/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   battleship.h
 * Author: Austin
 *
 * Created on October 25, 2022, 9:50 AM
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H


#include <utility>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <algorithm>

#include "battleplayer.h"

using namespace std;

class battleship {
private:
    set<pair<pair<int,int>,bool>> coords; //Holds a coordinate and a bool value which denotes if a ship is placed there or not
    set<pair<pair<int,int>,bool>> ships;
    void createMap();
    void createShips(); 
    void giveMap();
    void giveShips();
    
public:
    battleship();
    battleship(const battleship& orig);
    virtual ~battleship();
    void startGame();
    void placeShip();
};




#endif /* BATTLESHIP_H */

