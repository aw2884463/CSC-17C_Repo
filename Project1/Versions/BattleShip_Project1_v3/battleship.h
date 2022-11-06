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
#include<tuple> // for tuple
#include <set>
#include <algorithm>

#include "battleplayer.h"

using namespace std;

class battleship {
private:
    battleplayer players[2];
    set<tuple<pair<int,int>,bool,pair<int,int>>> coords; //Holds a coordinate in a pair and a bool stating if a ship was placed there, then another pair stating which ship and which point on that ship.
    set<tuple<int,int,bool>> ships; //Hols the different types of ships each player can have.
    void createMap(); //Files the coords variable
    void createShips(); //Files the ships variable 
    void giveMap(); //Set the player to have the correct map
    void giveShips(); //set the player to have the correct ships
    void gameLoop(); //This is the main loop of the game
    
public:
    battleship();
    battleship(const battleship& orig);
    virtual ~battleship();
    void startGame();
};




#endif /* BATTLESHIP_H */

