#include <iostream>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

class User {
    string id;
    string username;
    int balance;
    mutex mtx;
    
    public:
    User(string id1, string username1) {
        id = id1;
        username = username1;
        balance = 0;
    }
    
    void set_username(string username1) {
        mtx.lock();
        username = username1;
        mtx.unlock();
        return;
    }
    
    void add_balance(int sum) {
        mtx.lock();
        balance += sum;
        mtx.unlock();
        return;
    }
    
    int get_balance() {
        return balance;
    }
    string get_username() {
        return username;
    }
    
};

int main() {
    
    cout<<"Hello World";

    return 0;
}
