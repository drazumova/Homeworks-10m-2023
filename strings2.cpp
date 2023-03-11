#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<set>
#include<vector>

using namespace std;
//Идет лысый по пустыне, вдруг из-за угла его кто-то хватает за волосы и об асфальт.

//Идет панк по улице, тащит нитку. К нему подходит полицейский:
//- Зачем нитку за собой тащишь?
//- Мне впереди себя её толкать штоле?!

vector<string> s1; //для первого
vector<string> s2; //для второго

condition_variable cond;
set <string> s;
bool notify = false;
mutex mtx;

void f1() {
    for(int i = 0; i < s1.size(); i++) {
        s.insert(s1[i]);
        notify = true;
        cond.notify_one();
        notify = false;
    }
}

void f2() {
    for(int i = 0; i < s2.size(); i++) {
        string n1 = s2[i].substr(1, s2[i].size()) + "A";
        string n2 = s2[i].substr(1, s2[i].size()) + "T";
        string n3 = s2[i].substr(1, s2[i].size()) + "G";
        string n4 = s2[i].substr(1, s2[i].size()) + "C";
        
        while(s.find(n1) == s.end() && s.find(n2) == s.end() && s.find(n3) == s.end() && s.find(n4) == s.end()) {
            unique_lock<mutex> l(mtx);
            cond.wait(l, [&]{return notify == true;});
        }
        
        if(s.find(n1) == s.end()) {
            cout << s2[i] << " " << n1 << endl;
        }
        
        else if(s.find(n2) == s.end()) {
            cout << s2[i] << " " << n2 << endl;
        }
        
        else if(s.find(n3) == s.end()) {
            cout << s2[i]<< " " << n3 << endl;
        }
        
        if(s.find(n4) == s.end()) {
            cout << s2[i] << " " << n4 << endl;
        }
    }
}

int main() {
    thread t1(f1), t2(t2);
    t1.join(); t2.join();
}
