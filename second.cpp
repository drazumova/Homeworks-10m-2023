#include <iostream>
#include <vector>
#include <thread>
#include <windows.h>
using namespace std;

int hran;
int mmax = 0;
bool isHranUpdated = false;
bool isShowed = false; // показали ли мы новый максимум

void f1(){
    while(true){
        hran = rand();
        isHranUpdated = true;
        isShowed = false;
    }
}

void f2(){
    while(true){
        if(hran > mmax) mmax = hran;
        if(isHranUpdated && !isShowed){
            cout << mmax << endl;
            isShowed = true;
            isHranUpdated = false;
        }
    }
}

int main(){
    thread t1(f1), t2(f2);
    t1.join();
    t2.join();
}