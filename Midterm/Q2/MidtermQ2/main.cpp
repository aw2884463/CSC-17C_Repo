/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 26, 2022, 12:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */

void bublSrt(int [],int, int &);
void selSort(int [],int,int &);

int main(int argc, char** argv) {
    
    //Set the Random number seed
    srand(static_cast<unsigned int>(std::time(nullptr)));
    //Declare Variables.
    int opCount = 0;
    int size = 180000;
    int elements[size];
    int elements2[size];
    
    for(int i = 0;i < size;i++) {
        
        elements[i] = rand() % 1000;
        elements2[i] = elements[i];
    }
    int beg = time(0);
    selSort(elements,size,opCount);
    int end = time(0);
    cout << "It took about " << end-beg << " seconds to sort using the selSort and performed " << opCount << " operations"<< endl;
    for(int i = 0;i < size;i++) {
        
        elements[i] = elements2[i];
    }
    beg = time(0);
    opCount = 0;
    bublSrt(elements,size, opCount);
    end = time(0);
    cout << "It took about " << end-beg << " seconds to sort using the bublSrt and performed " << opCount << " operations"<< endl;

    return 0;
}

void selSort(int a[],int n, int &count){
    //Loop and declare variables
    int indx,min;
    count += 3;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        count+= 13;
        for(int i=pos+1;i<n;i++){
            count+=4;
            if(a[i]<min){
                count+=3;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n, int &count){
    //Keep looping and comparing until no swaps are left
    bool swap;
    count+=1;
    do{
        swap=false;
        count+=4;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            count+=7;
            if(a[i]>a[i+1]){
                count+=11;
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

