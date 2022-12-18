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
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

/*
 * 
 */

void selectionSort(short*, int const , int, int&);
short* makeIntArr(int n);
void printArr(short*, int n);
void mergeSort(short* array, int const begin, int const end,int&);
void merge(short* array, int const left, int const mid,int const right,int&);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0))); 
    
    int const size = 100000;
    int p = 2;
    int sCount = 0;
    int gCount = 0;
    short* arr = new  short[size];
    short* unsrted = makeIntArr(size);
    
    for(;p <= 100;p++) {
            for(int i =0;i < size;i++) {
                *(arr + i) = *(unsrted + i);
            }
            selectionSort(arr,size,p,sCount);
        cout /*<< "Selection Sort sorted the top p:" << p << " elements with an opCount of:"*/ << sCount << endl;
        sCount = 0;
            for(int i =0;i < size;i++) {
                *(arr + i) = *(unsrted + i);
            }
               mergeSort(arr,0,size,gCount);
       // cout << "Merge Sort sorted the whole array with an opCount of:" << gCount << endl << endl;
        gCount = 0;
    }   
    delete []arr;
    
    return 0;
}

void selectionSort(short* arr, int const size, int p, int& count) {
    for(int i=0;i<p;i++){
      int min=i; //indx of the smallest elem
      count+=6;
      for(int j=i+1;j<size;j++){
          count+=6;
        if(arr[j]<arr[min]) {
            count++;
            min=j;
        }
      }
      swap(arr[i],arr[min]);
      count+=11;
    }
}

void merge(short* hilow,int const beg,int const nlow,int const nhigh, int& count)
{
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge
    int *c=new int[span];  //Allocate Memory
    count+= 8;
    //Fill the array
    for(int i=0;i<span;i++){
        count+=4;
        if(cntl==nlow){
            c[i]=hilow[cnth++];
            count+=5;
        }else if(cnth==nhigh){
            c[i]=hilow[cntl++];
            count+=6;
        }else if(hilow[cntl]<hilow[cnth]){
            count+=9;
            c[i]=hilow[cntl++];
        }else{
            count+=6;
            c[i]=hilow[cnth++];
        }
    }
    //Copy back and deallocate memory
    for(int i=0;i<span;i++){
        hilow[beg+i]=c[i];
        count+=8;
    }
    count++;
    delete []c;
}
 
 // begin is for left index and end is
 // right index of the sub-array
 // of arr to be sorted */
void mergeSort(short* a, int const beg, int const end, int& count)
{
    int center=(beg+end)/2;
    count+=4;
    if((center-beg)>1) {
        count+=3;
        mergeSort(a,beg,center,count);
    }
    if((end-center)>1) {
        count+=3;
        mergeSort(a,center,end,count);
    }
    count++;
    merge(a,beg,center,end,count);
}

void printArr(short* arr,int n) {
    for(int i =0;i < n;i++) {
        cout << arr[i] << " ";
        if(i % 10 == 0 && i != 0) {
            cout << endl;
        }
    } 
    cout << endl;
}

short* makeIntArr(int n) {
    short* arr= new short[n]; 
    for(int i =0;i < n;i++) {
        arr[i] = rand() % 32767;
    }
    return arr;
}


