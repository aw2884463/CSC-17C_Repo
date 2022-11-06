/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: austi
 *
 * Created on October 23, 2022, 7:58 AM
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
void printShipMap(vector<pair<int,int>>&v,bool owner);
void printCoords(vector<pair<int,int>>&v);
bool checkSunk(ship& ship);
bool checkLoss(ship* ships);
void shootShip(vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap, ship* ships);
void placeShip(ship& ship, vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap);
bool checkFull(int cNum,vector<pair<int,int>>& shipMap,int index, ship& s);
vector<pair<int,int>>::iterator getCoord(vector<pair<int,int>>& v,int x,int y);
int createIndex(vector<pair<int,int>>& v, vector<pair<int,int>>::iterator);

int main(int argc, char** argv) {
    
    vector<pair<int,int>> coords = createCoords();//Holds coords of the map.
    vector<pair<int,int>> p1Map = createShipMap();//Holds ship #, and peg of ship.
    vector<pair<int,int>> p2Map = createShipMap();//Holds ship #, and peg of ship.
    ship* p1Ships = createShips();
    ship* p2Ships = createShips();
    bool gameOver = false;
    cout << "Welcome to my battleship game. Hope you like it!" << endl;
    cout << "Lets Begin. Well have player one place there ships now." << endl << endl;
    for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << p1Ships[i].size << endl; 
        placeShip(p1Ships[i],coords,p1Map);
    }
    cout << "Great. Now lets let player two place there ships." << endl;
    for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << p2Ships[i].size << endl; 
        placeShip(p2Ships[i],coords,p2Map);
    }
    cout << "Now that the ship's have been place lets start getting to the action!!!" << endl;
    
    while(!gameOver) {
        
        cout << "Player one will now shoot there shot!" << endl;
        printShipMap(p2Map,false);
        shootShip(coords,p2Map,p2Ships);
        printShipMap(p2Map,false);
        if (checkLoss(p2Ships)) {
            cout << "Player one wins by sinking the ships.";
            gameOver = true;
            break;
        }
        cout << "Player two will now shoot there shot!" << endl;
        printShipMap(p1Map,false);
        shootShip(coords,p1Map,p1Ships);
        printShipMap(p1Map,false);
        if (checkLoss(p1Ships)) {
            cout << "Player two wins by sinking the ships.";
            gameOver = true;
            break;
        }   
    }
    return 0;
}


void gameLoop() {
    
    
//    vector<pair<int,int>> coords = createCoords();//Holds coords of the map.
//    vector<pair<int,int>> p1Map = createShipMap();//Holds ship #, and peg of ship.
//    vector<pair<int,int>> p2Map = createShipMap();//Holds ship #, and peg of ship.
//    ship* p1Ships = createShips();
//    ship* p2Ships = createShips();
//    bool gameOver = false;
//    cout << "Welcome to my battleship game. Hope you like it!" << endl;
//    cout << "Lets Begin. Well have player one place there ships now." << endl << endl;
//    for(int i =0;i < 5;i++) {
//        cout << "Your ship has a length of :" << p1Ships[i].size << endl; 
//        placeShip(p1Ships[i],coords,p1Map);
//    }
//    cout << "Great. Now lets let player two place there ships." << endl;
//    for(int i =0;i < 5;i++) {
//        cout << "Your ship has a length of :" << p2Ships[i].size << endl; 
//        placeShip(p2Ships[i],coords,p2Map);
//    }
//    cout << "Now that the ship's have been place lets start getting to the action!!!" << endl;
//    
//    while(!gameOver) {
//        
//        cout << "Player one will now shoot there shot!" << endl;
//        printShipMap(p2Map,false);
//        shootShip(coords,p2Map,p2Ships);
//        printShipMap(p2Map,false);
//        if (checkLoss(p2Ships)) {
//            cout << "Player one wins by sinking the ships.";
//            gameOver = true;
//            break;
//        }
//        cout << "Player two will now shoot there shot!" << endl;
//        printShipMap(p1Map,false);
//        shootShip(coords,p1Map,p1Ships);
//        printShipMap(p1Map,false);
//        if (checkLoss(p1Ships)) {
//            cout << "Player two wins by sinking the ships.";
//            gameOver = true;
//            break;
//        }   
//    }
}


void shootShip(vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap, ship* ships) {
    
    int r,c,index;
    cout << "Where would you like to send you shot?" << endl;
    cout << "Enter the row coordinate now" <<endl;
    cin >> r;
    cout << "Enter the column coordinate now" <<endl;
    cin >> c;
    index = createIndex(board,getCoord(board,r,c));
    //cout << index;
    pair<int,int> temp = shipMap[index];
    if(temp.first == 0) {
        cout << "You missed try harder next time." << endl;
        setShipMap(shipMap,index,8,8);
        return;
    }
    if(temp.first == 8 || temp.first == 9) {
        cout << "You have already shot here." << endl;
        return;
    }
    else {
        cout << "You hit ship #" << temp.first << endl;
        //cout << ships[temp.first - 1].number << " " << temp.second; //@Debug
        ships[temp.first - 1].pegs[temp.second - 1] = true;
//        for(int i = 0;i< ships[temp.first - 1].size;i++) { //@Debug
//            cout << ships[temp.first - 1].pegs[i] << " ";  //@Debug
//        }                                                  //@Debug
//        cout << endl;
        checkSunk(ships[temp.first - 1]);
        setShipMap(shipMap,index,9,8);
        return;
    }
    
}

bool checkLoss(ship* ships) {
    for(int i = 0;i < 5;i++) {
        if(ships[i].sunk == false) {
            return false;
        }
    }
    return true;
}

bool checkSunk(ship& ship) {
    
    for(int i =0;i < ship.size;i++) {
        if(ship.pegs[i] == false) {
            
            return false;
        }
    }
    ship.sunk = true;
    return true;
}

ship* createShips() {
    
    ship * ships = new ship[5];
    int size = 2;
    for(int i = 0;i < 4;i++) {
        ships[i].number = i + 1;
        ships[i].size = size;
        ships[i].pegs = new bool[size];
        for(int j = 0;j < ships[i].size;j++) {
            ships[i].pegs[j] = false;
        }
        ships[i].sunk = false;
        size++;
        //cout << ships[i].number << " " << ships[i].size << " " << ships[i].sunk << endl;// @Debug
    }
    ships[4].number = 5;
    ships[4].size = 3;
    ships[4].pegs = new bool[ships[4].size];
    for(int i = 0;i < ships[4].size;i++) {
        ships[4].pegs[i] = false;
    }
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

void printShipMap(vector<pair<int,int>>&v, bool owner) {
    
    for(int i = 0;i < 9;i++) {
        cout << "= = ";
    }
    cout  << "=";
    for(int i = 0;i < v.size();i++) {
        if( i % 10 == 0) {
            cout << endl;
        }
        pair<int,int> temp = v[i];
        if(temp.first != 0 && temp.first != 8 && temp.first !=9) {
            if(owner) {
                cout << temp.first;
            }
            else {
                cout << "-";
            }
        }
        else if (temp.first == 9) {
            cout << "X";
        }
        else if (temp.first == 8) {
            cout << "O";
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
    cout <<"Where would you like to place your ship reference from point (1,1) of your ship" <<endl;
    cout << "Remember the board is a 10x10 (1,1)-(10,10)" <<endl;
    cout <<"Enter the row coordinate for your placement(top->bottom)" << endl;
    cin >> x;
    cout<< "Enter the column coordinate for your placement(left->right)" <<endl;
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
                         printShipMap(shipMap,true);
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
                if(y+ship.size <= 11) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap,true);
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
                         printShipMap(shipMap,true);
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
                if(x+ship.size <= 11) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap,true);
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
    printShipMap(shipMap,true);
}

