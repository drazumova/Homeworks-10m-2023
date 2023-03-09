#include <iostream>
#include<queue>
#include<mutex>
#include<condition_variable>

using namespace std;
struct Node { 
    int value; 
    Node* next; 
    
    Node(int x) {
        value = x;
    }
};

class Queue {
    private:
    Node* head;
    Node* tail;
    int s;
    mutex mtx;
    condition_variable cond;

    public:
    Queue() {
        s = 0;
    }
    
    Queue(int x) {
        head = new Node(x);
        tail = head;
        s = 1;
    }

    void put(int x) {
        mtx.lock();
        Node* n = new Node(x);
        
        if(s == 0) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n; 
            tail = n;
        }
        s++;
        cond.notify_one();
        mtx.unlock();
    }

    int pop() {
        mtx.lock();
        if(s == 0) {
            mtx.unlock();
            return -1;
        }
        
        if(s == 1) {
            int value = head -> value;
            s--;
            delete head;
            delete tail;
            mtx.unlock();
            return value;
        }
        
        s--;
        Node* prev_head = head; 
        head = head->next; 
        int value = prev_head->value;
        delete prev_head;
        
        mtx.unlock();
        return value;
    }

    size_t size() {
        return (size_t)s;
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
