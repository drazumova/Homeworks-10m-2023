#include <iostream>
#include<vector>

using namespace std;

template<typename T>
T sum(vector <T> a) {
    long long n = a.size();
    T vector_sum = a[0];
    for(int i = 1; i < n; i++) {
        vector_sum += a[i];
    }
    return vector_sum;
}

int main() {
    vector<int> a;
    for(int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    cout << sum<int>(a);
}
