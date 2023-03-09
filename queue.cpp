#include <iostream>
#include<queue>
#include<mutex>
#include<condition_variable>

using namespace std;

class Queue {
    private:
    queue <int> q;
    int s;
    mutex mtx;
    condition_variable cond;

    public:
    Queue() {
        s = 0;
    }

    void put(int x) {
        mtx.lock();
        q.push(x);
        s++;
        cond.notify_one();
        mtx.unlock();
    }

    int pop() {
        mtx.lock();
        int e = q.front();
        q.pop();
        s--;
        mtx.unlock();
        return e;
    }

    size_t size() {
        return (size_t)q.size();
    }
    
    int wait_and_pop() {
        if((int)size() == 0) {
            unique_lock<mutex> l(mtx);
            cond.wait(l, [&]{return s == 0;});
            return pop();
        }
        else {
            return pop();
        }
    }
};

int main() {

}
