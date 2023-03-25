#include <iostream>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

int n;
double sum = 0;

void f(vector<int> num) {
    if((int)num.size() < 4) {
        for(int i = 0; i < (int)num.size(); i++) {
            sum += (double)num[i];
        }
        return;
    }
    
    else {
        vector <int> num1;
        vector<int> num2;
        vector<int> num3;
        vector<int> num4;
        
        for(int i = 0; i < (int)num.size()/4; i++) {
            num1.push_back(num[i]);
        }
        for(int i = (int)num.size()/4; i < 2 * (int)num.size()/4; i++) {
            num2.push_back(num[i]);
        }
        for(int i = 2 * (int)num.size()/4; i < 3 * (int)num.size()/4; i++) {
            num3.push_back(num[i]);
        }
        for(int i = 3 * (int)num.size()/4; i < (int)num.size(); i++) {
            num4.push_back(num[i]);
        }
        
        thread t1(f, num1), t2(f, num2), t3(f, num3), t4(f, num4);
        t1.join(); t2.join(); t3.join(); t4.join();
        //sum /= 4;
    }
    
}

int main() {
    cin >> n;
    vector<int> num;
    for(int i = 0; i < n * n; i++) {
        int a; cin >> a;
        num.push_back(a);
    }
    
    thread t(f, num);
    t.join();
    cout << sum / (n * n); //здесь по идее может быть переполнение, но я не знаю, как иначе
} 

