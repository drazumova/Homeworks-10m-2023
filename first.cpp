#include <iostream>
#include <thread>
#include <vector>
using namespace std;

double summ = 0;

void ff(vector<double> a) {
    if (a.size() > 4) {
        int q = a.size() / 4;
        int w = a.size() / 2 - q;
        int e = a.size() * 3 / 4 - w - q;
        int t = a.size() - q - w - e;
        vector<double> qwer;
        vector<double> asdf;
        vector<double> zxcv;
        vector<double> tyui;
        for (int i = 0; i < q; i++) {
            qwer.push_back(a[i]);
        }
        for (int i = 0; i < w; i++) {
            asdf.push_back(a[i + q]);
        }
        for (int i = 0; i < e; i++) {
            zxcv.push_back(a[i + q + w]);
        }
        for (int i = 0; i < t; i++) {
            tyui.push_back(a[i + q + w + e]);
        }
        thread thr1(ff, qwer);
        thread thr2(ff, asdf);
        thread thr3(ff, zxcv);
        thread thr4(ff, tyui);
        thr1.join();
        thr2.join();
        thr3.join();
        thr4.join();
        
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
    vector<double> a;
    for (int i = 0; i < n * n; i++) {
        double x;
        cin >> x;
        a.push_back(x);
    }
    ff(a);
    cout << summ / (n*n);
}