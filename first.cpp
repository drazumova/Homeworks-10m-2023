#include <iostream>
#include <thread>
#include <vector>
using namespace std;

int summ = 0;

void ff(vector<int> a) {
    if (a.size() > 3) {
        int q = a.size() / 3;
        int w = a.size() * 2 / 3 - q;
        int e = a.size() - q - w;
        vector<int> qwer;
        vector<int> asdf;
        vector<int> zxcv;
        for (int i = 0; i < q; i++) {
            qwer.push_back(a[i]);
        }
        for (int i = 0; i < w; i++) {
            asdf.push_back(a[i + q]);
        }
        for (int i = 0; i < e; i++) {
            zxcv.push_back(a[i + q + w]);
        }
        thread thr1(ff, qwer);
        thread thr2(ff, asdf);
        thread thr3(ff, zxcv);
        thr1.join();
        thr2.join();
        thr3.join();
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            summ += a[i];
        }
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int m;
    cin >> m;
    ff(a);
    cout << summ % m;
}
