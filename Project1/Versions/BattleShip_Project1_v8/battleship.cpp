/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   battleship.cpp
 * Author: Austin
 * 
 * Created on November 5, 2022, 5:25 PM
 */

#include "battleship.h"

using namespace std;

battleship::battleship() {
    
    coords = createCoords();//Holds coords of the map.
    p1Map = createShipMap();//Holds ship #, and peg of ship.
    p2Map = createShipMap();//Holds ship #, and peg of ship.
    p1Stat = createStatTrack();
    p2Stat = createStatTrack();
    p1Ships = createShips();
    p2Ships = createShips();
}

battleship::battleship(const battleship& orig) {
}

battleship::~battleship() { 
}

void battleship::startGame() {
    
    bool gameOver = false;
    cout << "Welcome to my battleship game. Hope you like it!" << endl;
    cout << "Lets Begin. Well have player one place there ships now." << endl << endl;
    printShipMap(p1Map,true);
   for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << p1Ships[i].size << endl; 
        placeShip(p1Ships[i],coords,p1Map);
    }
    cout << "Great. Now lets let player two place there ships." << endl;
    printShipMap(p2Map,true);
    for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << p2Ships[i].size << endl; 
        placeShip(p2Ships[i],coords,p2Map);
    }
    cout << "Now that the ship's have been place lets start getting to the action!!!" << endl;
    while(!gameOver) {
        
        cout << "Player one will now shoot there shot!" << endl;
        cout << "Here is your view of player twos map." << endl;
        printShipMap(p2Map,false);
        shootShip(coords,p2Map,p2Ships,p1Stat);
        printShipMap(p2Map,false);
        if (checkLoss(p2Ships)) {
            cout << "Player one wins by sinking the ships.";
            gameOver = true;
            break;
        }
        cout << "Player two will now shoot there shot!" << endl;
        cout << "Here is your view of player ones map." << endl;
        printShipMap(p1Map,false);
        shootShip(coords,p1Map,p1Ships,p2Stat);
        printShipMap(p1Map,false);
        if (checkLoss(p1Ships)) {
            cout << "Player two wins by sinking the ships.";
            gameOver = true;
            break;
        }   
    }
    
    cout << endl << "Now lets see some stats." << endl;
    cout << "Player One:" << endl;
    printStat(p1Stat);
    cout  << endl << "Player Two:" << endl;
    printStat(p2Stat);

}

void battleship::printStat(map<char,int>& stats) {   
    cout << endl << "You had a total of " << stats['M'] << " misses." << endl;
    cout << "You had a total of " << stats['X'] << " hits." << endl;
}
void battleship::pushStat(char stat,map<char,int>& stats) {   
    stats[stat]++;   
}

map<char,int> battleship::createStatTrack() {
    
    map<char,int> stats;
    stats.insert({'M',0});
    stats.insert({'X',0});
    return stats;
}

bool battleship::checkFull(int cNum,list<pair<int,int>>& shipMap,int index, ship& ship) {
    
    int full = false;
    switch(cNum) {
        case 1:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - i;j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index - i];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        case 2:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + i;j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index + i];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        case 3:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - (10*i);j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index - (10*i)];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        case 4:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + (10*i);j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index + (10*i)];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        default:
            cout << "Buggy";
            break;
  
    }
    return full;
}

void battleship::placeShip(ship& ship, set<pair<int,int>>& board,list<pair<int,int>>& shipMap) {
    
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
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - i;j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index - i] = make_pair(ship.number,i+1);
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
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + i;j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index + i] = make_pair(ship.number,i+1);
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
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - (10*i);j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index - (10*i)] = make_pair(ship.number,i+1);
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
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + (10*i);j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index + (10*i)] = make_pair(ship.number,i+1);
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

int battleship::createIndex(set<pair<int,int>>& v, set<pair<int,int>>::iterator it) {
    return distance(v.begin(), it);
}

set<pair<int,int>>::iterator battleship::getCoord(set<pair<int,int>>& v,int x,int y) { 
    return find(v.begin(), v.end(), pair<int,int>(x,y));
}


void battleship::shootShip(set<pair<int,int>>& board,list<pair<int,int>>& shipMap, ship* ships, map<char,int>& stats) {
    
    int r = 0,
        c = 0,
        index = 0;
    while(r < 1 || r > 10 || c < 1 || c > 10) {
        cout << "Where would you like to send you shot?" << endl;
        cout << "Enter the row coordinate now" <<endl;
        cin >> r;
        cout << "Enter the column coordinate now" <<endl;
        cin >> c;
        if(r < 1 || r > 10 || c < 1 || c > 10) {
            cout << "Invalid coordinate" << endl;
        }      
    }
    index = createIndex(board,getCoord(board,r,c));
    //cout << index;
    list<pair<int,int>>::iterator it = shipMap.begin();
    for(int i =0;i < index;i++) {
        it++;
    }
    pair<int,int> temp = *it;
    //pair<int,int> temp = shipMap[index];
    if(temp.first == 0) {
        cout << "You missed try harder next time." << endl;
        setShipMap(shipMap,index,8,8);
        pushStat('M',stats);
        return;
    }
    if(temp.first == 8 || temp.first == 9) {
        cout << "You have already shot here. How do you mess up that bad?" << endl;
        return;
    }
    else {
        cout << "You hit ship #" << temp.first << endl;
        pushStat('X',stats);
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

bool battleship::checkLoss(ship* ships) {
    for(int i = 0;i < 5;i++) {
        if(ships[i].sunk == false) {
            return false;
        }
    }
    return true;
}

bool battleship::checkSunk(ship& ship) {
    
    for(int i =0;i < ship.size;i++) {
        if(ship.pegs[i] == false) {
            
            return false;
        }
    }
    ship.sunk = true;
    return true;
}

ship* battleship::createShips() {
    
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
set<pair<int,int>> battleship::createCoords() {
    
    set<pair<int,int>> temp;
    for(int i =1;i <= 10;i++) {
        for(int j =1;j <= 10;j++) {
            pair<int,int> p = make_pair(i,j);
            temp.insert(p);
        }
    }
    return temp;
}
list<pair<int,int>> battleship::createShipMap() {
    
    list<pair<int,int>> temp;
    for(int i =1;i <= 10;i++) {
        for(int j =1;j <= 10;j++) {
            pair<int,int> test = make_pair(0,0);
            temp.push_back(test);
        }
    }
    return temp;
}
void battleship::setShipMap(list<pair<int,int>>&v,int i,int x,int y) {
    list<pair<int,int>>::iterator it = v.begin();
    for(int n =0;n < i;n++) {
        it++;
    }
    *it = make_pair(x,y);   
}

void battleship::printShipMap(list<pair<int,int>>&v, bool owner) {
    
    for(int i = 0;i < 9;i++) {
        cout << "=  =  ";
    }
    cout  << "=";
    list<pair<int,int>>::iterator it;
    int count = 0;
    for(it = v.begin();it != v.end();it++) {
        if( count % 10 == 0) {
            cout << endl << endl;
        }
        count++;
        pair<int,int> temp = *it;
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
        cout << "     ";
    }
    cout  << endl;
    for(int i = 0;i < 9;i++) {
        cout << "=  =  ";
    }
    cout  << "=" << endl;
    cout << endl << endl;
}
void battleship::printCoords(set<pair<int,int>>&v) {
    
    set<pair<int,int>>::iterator it;
    int count = 0;
    for(it = v.begin();it != v.end();it++) {
        if( count % 10 == 0) {
            cout << endl;
        }
        pair<int,int> temp = *it;
        cout << "(" << temp.first << "," << temp.second << ")  ";
        count++;
    }
    cout << endl << endl;
}
