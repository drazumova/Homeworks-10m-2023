#include <iostream>
#include<vector>

using namespace std;

template<typename T>
T combine(T a, T b) {
    return a;
}

template<typename T>
concept N = requires(T a) {
    { a.combine() } -> std :: convertible_to <T>;
};

template<typename T>
requires N<T>
class SegTree{
    vector <T> tree;
    int n;
    int nn;
    
    void build (vector<T> a, int v, int tl, int tr) {
        if (tl == tr) tree[v] = a[tl];
 
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
        }
    }
    
    void update1 (int v, int tl, int tr, int index, T nv) {
        if (tl == tr) tree[v] = nv;
 
        else {
            int tm = (tl + tr) / 2;
            if (index <= tm)
                update (v*2, tl, tm, index, nv);
            else
                update (v*2+1, tm+1, tr, index, nv);
                tree[v] = combine(tree[v*2], tree[v*2+1]);
            }
        }
    
    
    T combinee(int v, int tl, int tr, int l, int r) {
        if (l > r) return T();
        if (l == tl && r == tr) return tree[v];
 
        int tm = (tl + tr) / 2;
        return combine(combinee (v*2, tl, tm, l, min(r,tm)), combinee(v*2+1, tm+1, tr, max(l,tm+1), r));
    }    
    
    public:
    SegTree(vector<T> a) {
        n = a.size();
    
        nn = 1;
        while(nn < n)
            nn *= 2;
        
        tree.resize(2 * nn);
        build(a, 1, 0, nn - 1);
    }
    
    void update(int index, T value) {
        update1(1, 0, nn - 1, index - 1, value);
    }
    
    T get_value (int r, int l) { // c 1
        return combinee(1, 0, nn - 1, r - 1, l - 1);
    }
};

int main() {
}