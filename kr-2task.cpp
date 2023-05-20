#include <iostream>
#include<vector>
#include<set>
#include<iterator>

using namespace std;

template<typename T>
T sum(T a) {
    return a;
}
template<typename T>
T sum(vector<T> a) {
    T s = a[0];
    for(int i = 1; i < a.size(); i++) {
        s += a[i];
    }
    return s;
}

template<typename T>
T sum(set<T> a) {
    T s = * a.begin();
    for (auto i : a) {
        s += i;
    }
    s -= *a.begin();
    return s;
}

int main() {
    set<int> a;
    set<int> :: iterator it = a.begin();
    
    int a1 = 10;
    vector<string> a2 {"1", "2", "3"};
    set<double> a3 {1.5, 2.0};

    cout << sum<int>(a1) << endl; // 10
    cout << sum(a2) << endl; // "123"
    cout << sum(a3) << endl; // 3.5
    
}
