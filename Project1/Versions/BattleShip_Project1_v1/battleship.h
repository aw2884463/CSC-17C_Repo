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
#include <cmath>
#include <ctime>

using namespace std;

class battleship {
private:
    set<pair<int,int>> map1;
    set<pair<int,int>> map2;
    void createMap();
    void createShips();
    
    
public:
    battleship();
    battleship(const battleship& orig);
    virtual ~battleship();
    void startGame();
};




#endif /* BATTLESHIP_H */

