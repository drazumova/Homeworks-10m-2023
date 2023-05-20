#include <iostream>

using namespace std;

template <typename T>
T* alloc (T a) {
    T* b = new T;
    *b = a;
    return b;
}

int main() {
    // int* a = new int;
    // *a = 10;
    // cout << *a;
}
