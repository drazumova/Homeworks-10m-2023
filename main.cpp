#include <iostream>
#include<thread>
#include<mutex>
          using namespace std;
     mutex mtx;
  void f() 
{
    for(int i = 1; i <= 1000000; i++) {
        mtx.lock();
        cout << i << ' ' << this_thread::get_id() << '\n';
        mtx.unlock();
    }
}
int main() {
    thread t1(f), t2(f), t3(f);
    t1.join();
    t2.join();
    t3.join();
}