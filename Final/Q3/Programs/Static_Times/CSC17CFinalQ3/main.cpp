/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on December 8, 2022, 9:16 PM
 */

#include <cstdlib>
#include <queue>
#include <list>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>


using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    
    vector<pair<int,int>> clerks;//Holds all clerks
    vector<float> wTime;//Holds all wait times
    queue<bool> line;//Holds how many customers are in line
    list<float> times;
    list<int> trackedTimes;
    
    int cMax = 0,//Holds the max customers in line at any point
        begin = 0,//Start wait time
        end = 0;//End wait time
    clerks.push_back(make_pair(8,8));//Speed 1/min, Minimum Start Time
    clerks.push_back(make_pair(12,12));//Speed .75/min, Minimum Start Time
    clerks.push_back(make_pair(16,16));//Speed .50/min, Minimum Start Time
    
    //8 Loops = 1 min.
    //Test ran for 12 hours.
    for(int i = 0;i < 8*60*12;i++) {
        if(i % 2 == 0) {
            //Adds 15 seconds to every persons wait time.
            for(list<float>::iterator it = times.begin();it != times.end();it++) {
                int temp = *it;
                temp++;
                *it = temp;
            }
            //Every 15 seconds we add another person to the line.
            line.push(false);
            times.push_front(0);
            //Check the if the line max has increased.
           if(cMax < line.size()) {
               cMax = line.size();
           } 
        } 
        //Adds as many clerks as we need
        //cout  << "Before:"<< clerks.size() << " " << line.size() << endl; ///@Debug
        while((clerks.size() - 3) < line.size() / 5) {
            //cout << (clerks.size() - 3) << " " << (line.size() / 5) << endl; ///@Debug
            clerks.push_back(make_pair(8,i + 8));//Speed 1/min, Minimum Start Time;  
        } 
        //Remove as many clerks as we need
        while((clerks.size() - 3) > (line.size() / 5)) {
            clerks.pop_back();
        }
        //cout  << "After:"<< clerks.size() << " " << line.size() << endl; ///@Debug
        //Loop to check if a clerk is done with a customer yet.
        for(int j = 0;j < clerks.size();j++) {
            if( i >= clerks[j].first && i % clerks[j].first == 0) { 
                if(clerks[j].second <= i  && line.size() > 0) {
                    //cout << "Clerk:" << j+1 << " time =" << (i/2)*15 << "seconds"<< endl; ///@Debug
                    line.pop();
                    int time = times.back();
                    trackedTimes.push_front(time);
                    times.pop_back();
                }
            }
            clerks[j].second = false;
        }
          
    }
    cout << "Max customers in line was:"<< cMax << endl;
    float avg = 0;
    for(list<float>::iterator it = times.begin();it != times.end();it++) {
        avg += *it;
        
    }
    cout << "Customers still left in line after simulation:" << line.size() << endl;
    cout << "The average wait time was:"<< (((avg / times.size())) * 15) / 60 << " minutes." << endl;
    return 0;
}


