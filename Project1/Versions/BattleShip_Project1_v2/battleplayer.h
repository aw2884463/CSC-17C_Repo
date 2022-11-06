/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   battleplayer.h
 * Author: Austin
 *
 * Created on October 26, 2022, 1:12 PM
 */
#include <utility>
#include <iostream>
#include <iterator>
#include <list>
#include <cstdlib>
#include <bitset>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

#ifndef BATTLEPLAYER_H
#define BATTLEPLAYER_H

class battleplayer {
public:
    battleplayer();
    battleplayer(const battleplayer& orig);
    virtual ~battleplayer();
    bitset<5> getShipStats() {return shipStats;}
private:
    bitset<5> shipStats;
    set<pair<pair<int,int>,bool>> pMap;
    set<pair<pair<int,int>,bool>> ships;
    

};

#endif /* BATTLEPLAYER_H */

