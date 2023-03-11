#include <iostream>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

int n, m;
long long sum = 0;

void f(vector<int> num) {
    if((int)num.size() < 3) {
        for(int i = 0; i < (int)num.size(); i++) {
            sum += num[i];
            sum %= m;
        }
        return;
    }
    
    else {
        vector <int> num1;
        vector<int> num2;
        vector<int> num3;
        
        for(int i = 0; i < n/3; i++) {
            num1.push_back(num[i]);
        }
        for(int i = n/3; i < 2 * n/3; i++) {
            num2.push_back(num[i]);
        }
        for(int i = 2 * n/3; i < n; i++) {
            num3.push_back(num[i]);
        }
        
        thread t1(f, num1), t2(f, num2), t3(f, num3);
        t1.join(); t2.join(); t3.join();
    }
    
}

int main() {
    cin >> n;
    vector<int> num;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        num.push_back(a);
    }
    cin >> m;
    
    thread t(f, num);
    t.join();
    cout << sum;
}
