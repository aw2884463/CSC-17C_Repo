/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   battleship.h
 * Author: Austin
 *
 * Created on November 5, 2022, 5:25 PM
 */
#include <cstdlib>
#include <vector>
#include <tuple>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>


#include "ship.h"

using namespace std;

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class battleship {
public:
    battleship();
    battleship(const battleship& orig);
    virtual ~battleship();
    void startGame();
private:
    
    set<pair<int,int>> coords;
    list<pair<int,int>> p1Map;
    list<pair<int,int>> p2Map;
    map<char,int> p1Stat;
    map<char,int> p2Stat;
    ship* p1Ships;
    ship* p2Ships;
    
    
    set<pair<int,int>> createCoords();
    list<pair<int,int>> createShipMap();
    ship* createShips();
    void setShipMap(list<pair<int,int>>&v,int,int,int);
    void printShipMap(list<pair<int,int>>&v,bool owner);
    void printCoords(set<pair<int,int>>&v);
    void printStat(map<char,int>& stats);
    void pushStat(char,map<char,int>&);
    map<char,int> createStatTrack();
    bool checkSunk(ship& ship);
    bool checkLoss(ship* ships);
    void shootShip(set<pair<int,int>>& board,list<pair<int,int>>& shipMap, ship* ships, map<char,int>&);
    void placeShip(ship& ship, set<pair<int,int>>& board,list<pair<int,int>>& shipMap);
    bool checkFull(int cNum,list<pair<int,int>>& shipMap,int index, ship& s);
    set<pair<int,int>>::iterator getCoord(set<pair<int,int>>& board,int x,int y);
    int createIndex(set<pair<int,int>>& board, set<pair<int,int>>::iterator);

};

#endif /* BATTLESHIP_H */

