/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on December 8, 2022, 4:13 PM
 */


#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;


void dijkstra(int source,vector<pair<int, int>>*,int,string []);

int main() {
  
    
  const int size = 7;
  vector<pair<int, int>> adj[size];
  string names[size] = {"SFO","JFK","DFW","BOS","ORD","MIA","LAX"};
  int SFO = 0;
  int JFK = 1;
  int DFW = 2;
  int BOS = 3;
  int ORD = 4;
  int MIA = 5;
  int LAX = 6;
  adj[SFO].push_back(make_pair(BOS, 2703));//Added SFO->BOS
  adj[BOS].push_back(make_pair(SFO, 2703));////////////////
  adj[SFO].push_back(make_pair(ORD, 1847));//Added SFO->ORD
  adj[ORD].push_back(make_pair(SFO, 1847));////////////////
  adj[ORD].push_back(make_pair(BOS, 868));//Added ORD->BOS
  adj[BOS].push_back(make_pair(ORD, 868));////////////////
  adj[ORD].push_back(make_pair(JFK, 743));//Added ORD->JFK
  adj[JFK].push_back(make_pair(ORD, 743));////////////////
  adj[JFK].push_back(make_pair(BOS, 189));//Added JFK->BOS
  adj[BOS].push_back(make_pair(JFK, 189));////////////////
  adj[SFO].push_back(make_pair(DFW, 1465));//Added SFO->DFW
  adj[DFW].push_back(make_pair(SFO, 1465));////////////////
  adj[DFW].push_back(make_pair(ORD, 803));//Added DFW->ORD
  adj[ORD].push_back(make_pair(DFW, 803));////////////////
  adj[DFW].push_back(make_pair(MIA, 1124));//Added DFW->MIA
  adj[MIA].push_back(make_pair(DFW, 1124));////////////////
  adj[MIA].push_back(make_pair(JFK, 1093));//Added MIA->JFK
  adj[JFK].push_back(make_pair(MIA, 1093));////////////////
  adj[SFO].push_back(make_pair(LAX, 338));//Added SFO->LAX
  adj[LAX].push_back(make_pair(SFO, 338));////////////////
  adj[LAX].push_back(make_pair(DFW, 1234));//Added LAX->DFW
  adj[DFW].push_back(make_pair(LAX, 1234));////////////////
  adj[LAX].push_back(make_pair(MIA, 2341));//Added LAX->MIA
  adj[MIA].push_back(make_pair(LAX, 2341));////////////////

  
  cout << "Distances from ORD." << endl;
  dijkstra(ORD,adj,size,names);
  cout << "Shortest distance from ORD->LAX = 2037 ORD->DFW->LAX" << endl << endl;
  cout << "Distances from JFK." << endl;
  dijkstra(JFK,adj,size,names);
  cout << "Shortest distance from JFK->SFO = 2590 JFK->ORD->SFO" << endl;
  return 0;
}


 void dijkstra(int source,vector<pair<int, int>>*adj,int N,string names[]) {
  //Holds shortest distances.
  vector<int> distances(N, INT_MAX);

  //Priority queue that finds the next node to visit.
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0,source)); // Add the source node with distance 0.
  distances[source] = 0; // distance to source node is 0.

  //While there are nodes in the queue.
  while (!pq.empty()) {
    //Get the next node to visit.
    int distance = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    //If the distance to the node is already shorter, ignore this node.
    if (distance > distances[node]) continue;

    //Loop that visit all the neighbors of the node.
    for (auto neighbor : adj[node]) {
      int newDistance = distance + neighbor.second; // Distance to neighbor through the current node.
      int neighborNode = neighbor.first;

      //Updates distances if shorter.
      if (newDistance < distances[neighborNode]) {
        distances[neighborNode] = newDistance;
        pq.push(make_pair(newDistance, neighborNode));
      }
      
    }
  }

  //Print distances to all the nodes.
  for (int i = 0; i < N; i++) {
    cout << "Distance from node " << names[source] << " to node " << names[i] << ": " << distances[i] << endl;
  }
}