#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex m;
void f(){
    for(int i=1;i<=10;i++){
        m.lock();
        cout<<i<<" "<<this_thread::get_id()<<"\n";
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
int main(){
    std::thread t1(f);
    std::thread t2(f);
    std::thread t3(f);
    t1.join();
    t2.join();
    t3.join();
}