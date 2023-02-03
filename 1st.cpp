#include <iostream>
#include<mutex>
#include<thread>

using namespace std;

std :: mutex mtx;

void f() {
    for(int i = 1; i <= 100; i++) {
        mtx.lock();
        cout << i << " ";
        cout << std :: this_thread :: get_id() << endl;
        mtx.unlock();
    }
}

int main() {
    thread t1(f), t2(f), t3(f);
    t1.join();
    t2.join();
    t3.join();
}
