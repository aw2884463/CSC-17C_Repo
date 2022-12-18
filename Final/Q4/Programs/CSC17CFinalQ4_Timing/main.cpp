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

void selectionSort(short*, int, int);
short* makeIntArr(int n);
void printArr(short*, int n);
void mergeSort(short* array, int const begin, int const end);
void merge(short* array, int const left, int const mid,int const right);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0))); 
    
    int size = 100000;
    int p = 1000;
    float tTime;
    short* arr = new  short[size];
    short* unsrted = makeIntArr(size);
    
    for(;p <= size;p+=10000) {
            for(int i =0;i < size;i++) {
                *(arr + i) = *(unsrted + i);
            }
        int sT = time(0);
            selectionSort(arr,size,p);
        int eT = time(0);
        cout << "It took about " << eT - sT << " seconds for selection sort to sort the array with p:" << p << " elements being sorted." << endl;       
            for(int i = 0;i < 100;i++) {
                for(int i =0;i < size;i++) {
                    *(arr + i) = *(unsrted + i);
                }
               sT = time(0);
               mergeSort(arr,0,size);
               eT = time(0);
               tTime += eT-sT;
            }
        cout << "It took about " << tTime / 100 << " seconds for merge sort to sort the array." << endl;
        tTime = 0;
    }
    
    delete []arr;
    
    return 0;
}

void selectionSort(short* arr, int size, int p) {
    for(int i=0;i<p;i++){
      int min=i; //indx of the smallest elem
      for(int j=i+1;j<size;j++){
        if(arr[j]<arr[min]) min=j;
      }
      swap(arr[i],arr[min]);
    }
}

void merge(short* hilow,int const beg,int const nlow,int const nhigh)
{
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge
    int *c=new int[span];  //Allocate Memory
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){
            c[i]=hilow[cnth++];
        }else if(cnth==nhigh){
            c[i]=hilow[cntl++];
        }else if(hilow[cntl]<hilow[cnth]){
            c[i]=hilow[cntl++];
        }else{
            c[i]=hilow[cnth++];
        }
    }
    //Copy back and deallocate memory
    for(int i=0;i<span;i++){
        hilow[beg+i]=c[i];
    }
    delete []c;
}
 
 // begin is for left index and end is
 // right index of the sub-array
 // of arr to be sorted */
void mergeSort(short* a, int const beg, int const end)
{
    int center=(beg+end)/2;
    if((center-beg)>1)mergeSort(a,beg,center);
    if((end-center)>1)mergeSort(a,center,end);
    merge(a,beg,center,end);
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


