#include <iostream>
#include<future>
#include<thread>

using namespace std;

void f1(promise <string> p) {
    string name; cin >> name;
    p.set_value(name);
}

void f2(future <string> ft) {
    string name = ft.get();
    cout << "Добро пожаловать, " << name;
}

int main(){
    promise <string> p;
    future <string> ft = p.get_future();
    thread t1(f1, move(p)), t2(f2, move(ft));

    t1.join(); t2.join();
}
