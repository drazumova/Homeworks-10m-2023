#include <iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<condition_variable>

using namespace std;
vector <int> numbers;
condition_variable cond;
mutex mtx;
bool notify = false;

void f1() {
    while(true) {
        mtx.lock();
        int x = rand();
        numbers.push_back(x);
        notify = true;
        cond.notify_one();
        mtx.unlock();
    }
}

void f2() {
    while(true) {
        unique_lock<mutex> l(mtx);
        cond.wait(l, [&]{return notify == true;});
        notify = false;
        long long max = 0;
        for(long long i = 0; i < numbers.size(); i++) {
            if(max < numbers[i]) {
                max = numbers[i];
            }
        }
        cout << max << endl;
    }
    
}

int main() {
    thread t1(f1), t2(f2);
    t1.join(); t2.join();
} 

