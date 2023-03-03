#include <iostream>
#include<future>
#include<thread>
#include<random>
#include<vector>

using namespace std;

int n, s;

long long factorial(int x) {
    long long f = 1;
    for(int i = 2; i <= x; i ++) {
    f *= i;
    //cout « f « endl;
    }
    return f;
}

void f1() {
    srand(s);
    vector <future <long long>> ft;
    vector<int> numbers;

    for(int i = 0; i < n; i++) {
        int x = random() % 50;
        numbers.push_back(x);
        future <long long> ftt = async(factorial, x);
        ft.push_back(move(ftt));
    }

    for(int i = 0; i < n; i++) {
        long long f = ft[i].get();
        cout << numbers[i] << " : " << f << endl;
}
}

int main(){
    cin >> n >> s;
    thread t(f1);
    t.join();
}
