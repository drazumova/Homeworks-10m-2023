#include <iostream>
#include <vector>
using namespace std;
template<typename T>
T sum(vector<T> a) {
    T result = a[0];
    for (int i=1;i<a.size();i++) {
        result += a[i];
    }
    return result;
}
int main(){
    vector<int>n{1,2,3};
    cout<<sum(n);
}
