#include <iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

long long a = 0;

void f1() {
    while(true) {
    int x; 
    cin >> x;
    mtx.lock();
    a += x;
    mtx.unlock();
    }
}
void f2() {
    while(true) {
        mtx.lock();
        cout << a << endl;
        mtx.unlock();
    }
}

int main() {
    thread t1(f1), t2(f2);
    t1.join(); t2.detach();
}
