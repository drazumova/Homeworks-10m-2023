#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex m;
long long A=0;
void f(){
    m.lock();
    while(true){
        int a;
        cin>>a;
        A+=a;
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void print(){
    while(true){
        m.lock();
        cout<<A<<"\n";
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
int main(){
    std::thread t1(f);
    std::thread t2(print);
    t1.join();
    t2.join();
}