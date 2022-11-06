/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: austi
 *
 * Created on October 30, 2022, 7:58 AM
 */

#include <cstdlib>
#include <vector>
#include <tuple>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 
 */


struct ship {
    int number;
    int size;
    bool *pegs;
    bool sunk;
};

vector<pair<int,int>> createCoords();
vector<pair<int,int>> createShipMap();
ship* createShips();
void setShipMap(vector<pair<int,int>>&v,int,int,int);
void printShipMap(vector<pair<int,int>>&v);
void printCoords(vector<pair<int,int>>&v);
void shootShip();
void placeShip(ship& ship, vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap);
bool checkFull(int cNum,vector<pair<int,int>>& shipMap,int index, ship& s);
vector<pair<int,int>>::iterator getCoord(vector<pair<int,int>>& v,int x,int y);
int createIndex(vector<pair<int,int>>& v, vector<pair<int,int>>::iterator);

int main(int argc, char** argv) {
    
    vector<pair<int,int>> coords = createCoords();//Holds coords of the map
    vector<pair<int,int>> setMap = createShipMap();//Holds ship #, and peg of ship
    ship* ships = createShips();
    //cout << ships[0].size;
    for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << ships[i].size << endl; 
        placeShip(ships[i],coords,setMap);
    }
    return 0;
}


ship* createShips() {
    
    ship * ships = new ship[5];
    int size = 2;
    for(int i = 0;i < 4;i++) {
        ships[i].number = i + 1;
        ships[i].size = size;
        ships[i].pegs = new bool[size];
        ships[i].pegs={};
        ships[i].sunk = false;
        size++;
        //cout << ships[i].number << " " << ships[i].size << " " << ships[i].sunk << endl;// @Debug
    }
    ships[4].number = 5;
    ships[4].size = 3;
    ships[4].pegs = new bool[ships[4].size];
    ships[4].pegs={};
    ships[4].sunk = false;
    return ships;
}
vector<pair<int,int>> createCoords() {
    
    vector<pair<int,int>> temp;
    for(int i =1;i <= 10;i++) {
        for(int j =1;j <= 10;j++) {
            pair<int,int> p = make_pair(i,j);
            temp.push_back(p);
        }
    }
    return temp;
}
vector<pair<int,int>> createShipMap() {
    
    vector<pair<int,int>> temp;
    for(int i =1;i <= 10;i++) {
        for(int j =1;j <= 10;j++) {
            pair<int,int> test = make_pair(0,0);
            temp.push_back(test);
        }
    }
    return temp;
}
void setShipMap(vector<pair<int,int>>&v,int i,int x,int y) {    
    v[i] = make_pair(x,y);   
}

void printShipMap(vector<pair<int,int>>&v) {
    for(int i = 0;i < 9;i++) {
        cout << "= = ";
    }
    cout  << "=";
    for(int i = 0;i < v.size();i++) {
        if( i % 10 == 0) {
            cout << endl;
        }
        pair<int,int> temp = v[i];
        if( temp.first != 0) {
            cout << temp.first;
        }
        else {
            cout << "-";
        }
        cout << "   ";
    }
    cout << endl;
    for(int i = 0;i < 9;i++) {
        cout << "= = ";
    }
    cout  << "=" << endl;
    cout << endl << endl;
}
void printCoords(vector<pair<int,int>>&v) {
    
    for(int i = 0;i < v.size();i++) {
        if( i % 10 == 0) {
            cout << endl;
        }
        pair<int,int> temp = v[i];
        cout << "(" << temp.first << "," << temp.second << ")  " ;
        
    }
    cout << endl << endl;
}

int createIndex(vector<pair<int,int>>& v, vector<pair<int,int>>::iterator it) {
    
    return it - v.begin();
}

bool checkFull(int cNum,vector<pair<int,int>>& shipMap,int index, ship& ship) {
    
    int full = false;
    switch(cNum) {
        case 1:
                    for(int i = 0;i < ship.size;i++) {
                        pair<int,int> temp = shipMap[index - i];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                        }
                    }
            break;
        case 2:
                    for(int i = 0;i < ship.size;i++) {
                        pair<int,int> temp = shipMap[index + i];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                        }
                    }
            break;
        case 3:
                    for(int i = 0;i < ship.size;i++) {
                        pair<int,int> temp = shipMap[index - (10*i)];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                        }
                    }
            break;
        case 4:
                    for(int i = 0;i < ship.size;i++) {
                        pair<int,int> temp = shipMap[index + (10*i)];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                        }
                    }
            break;
        default:
            cout << "Buggy";
            break;
  
    }
    return full;
}

vector<pair<int,int>>::iterator getCoord(vector<pair<int,int>>& v,int x,int y) {
    
    return find(v.begin(), v.end(), pair<int,int>(x,y));
}

void placeShip(ship& ship, vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap) {
    
    int x,y,r;
    printShipMap(shipMap);
    cout <<"Where would you like to place your ship reference from point (1,1) of your ship" <<endl;
    cout << "Remember the board is a 10x10 (1,1)-(10,10)" <<endl;
    cout <<"Enter the x coordinate for your placement(left->right)" << endl;
    cin >> x;
    cout<< "Enter the y coordinate for your placement(top->bottom)" <<endl;
    cin >> y;
    cout << "Enter the rotation for your ship" << endl;
    cout << "1)Left , 2)Right , 3)Up , 4)Down" << endl;
    cin >> r;
    if(x <= 10 && y <= 10 && r <= 4 && x >=1 && y >= 1 && r >=1) {
        switch(r) {
            case 1:
                if(y-ship.size >= 0) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        shipMap[index - i] = make_pair(ship.number,i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            case 2:
                if(y+ship.size <= 10) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        shipMap[index + i] = make_pair(ship.number,i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            case 3:
                if(x-ship.size >= 0) {

                    int index = createIndex(board,getCoord(board,x,y));
                    //shipMap[index] = make_pair(1,1); @Debug
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        shipMap[index - (10*i)] = make_pair(ship.number,i+1);
                    }
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            case 4:
                if(x+ship.size <= 10) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        shipMap[index + (10*i)] = make_pair(ship.number,i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            default:
                cout << "Invalid coordinate was not caught by the check" << endl;
        }
        
    }
    else {
        cout << "Invalid coordinate" <<endl;
        placeShip(ship,board,shipMap);
    }
    printShipMap(shipMap);
    cout << "I made it here." << endl;
}

