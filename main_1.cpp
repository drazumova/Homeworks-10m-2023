#include <iostream>
#include<thread>
#include<mutex>
          using namespace std;
     mutex mtx;
long long x = 0;
bool t = true;
int y; 
void f() 
{    while(cin >> y) {
    mtx.lock();
    x += y;
    mtx.unlock();
    }
}
void g() 
{    while(t) {
        mtx.lock();
        cout << x << endl;
        mtx.unlock();
    }
}
int main() {
    thread t1(f), t2(g);
    t1.join(); 
    t2.join();
}