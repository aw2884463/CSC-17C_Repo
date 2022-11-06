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
vector<pair<int,int>> createCoords();
vector<pair<int,int>> createShipMap();
void setShipMap(vector<pair<int,int>>&v,int,int,int);
void placeShip(tuple<int,int,bool> ship, vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap);
vector<pair<int,int>>::iterator getCoord(vector<pair<int,int>>& v,int x,int y);
int createIndex(vector<pair<int,int>>& v, vector<pair<int,int>>::iterator);

int main(int argc, char** argv) {
    
    vector<pair<int,int>> coords = createCoords();//Holds coords of the map
    vector<pair<int,int>> setMap = createShipMap();//Holds ship #, and peg of ship
    tuple<int,int,bool> ship = make_tuple(1,3,false); //Holds ship #, length, destroyed?
    placeShip(ship,coords,setMap);
    return 0;
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

int createIndex(vector<pair<int,int>>& v, vector<pair<int,int>>::iterator it) {
    
    return it - v.begin();
}

vector<pair<int,int>>::iterator getCoord(vector<pair<int,int>>& v,int x,int y) {
    
    return find(v.begin(), v.end(), pair<int,int>(x,y));
}

void placeShip(tuple<int,int,bool> ship, vector<pair<int,int>>& board,vector<pair<int,int>>& shipMap) {
    
    int x,y,r;
    cout << endl <<"Where would you like to place your ship reference from point (1,1) of your ship" <<endl;
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
                if(x-get<1>(ship) >= 0) {
                    int index = createIndex(board,getCoord(board,x,y));
                    for(int i = 0;i < get<1>(ship);i++) {
                        shipMap[index - (10*i)] = make_pair(get<0>(ship),i+1);
                    }
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                }
                break;
            case 2:
                if(x+get<1>(ship) <= 10) {
                    int index = createIndex(board,getCoord(board,x,y));
                    for(int i = 0;i < get<1>(ship);i++) {
                        shipMap[index + (10*i)] = make_pair(get<0>(ship),i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                }
                break;
            case 3:
                if(y-get<1>(ship) >= 0) {
                    int index = createIndex(board,getCoord(board,x,y));
                    for(int i = 0;i < get<1>(ship);i++) {
                        shipMap[index - i] = make_pair(get<0>(ship),i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                }
                break;
            case 4:
                if(y+get<1>(ship) <= 10) {
                    int index = createIndex(board,getCoord(board,x,y));
                    for(int i = 0;i < get<1>(ship);i++) {
                        shipMap[index + i] = make_pair(get<0>(ship),i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
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
    
}

