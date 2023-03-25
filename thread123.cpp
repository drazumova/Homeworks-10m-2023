#include<bits/stdc++.h>
using namespace std;
int N=9;
long long **n;
long long sar(int a, int b, int c, int d){
	if(b - a < 8){
		double sur = 0;
		for(int i = 0;( a < i || a == i) && i < b; i++){
			for(int j = 0; c <= j && j < d; j++){
				sur+=n[i][j];
			}
		}
		sur = sur /((b-a)*(d-c));
		return sur;
	}
	future<long long > c1 = async(sar, a, b/2, c, d/2);
	future<long long> c2 = async(sar, a, b/2, (c + d/2), d);
	future<long long> c3 = async(sar, (a + b/2), b, c, d/2);
	future<long long> c4 = async(sar, (a + b/2), b, (c + d/2), d);
	return c1.get() +  c2.get() +  c3.get() +  c4.get();
}
int main(){
	cin >> N;
	n = new long long*  [N];
	for(int i =  0; i < N; i ++){
		n[i] = new long long [N];
		
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> n[i][j];
		}
	}
	thread th1([&]()
	{
		cout << sar(0, N, 0, N);
	}
	);
	th1.join();
}