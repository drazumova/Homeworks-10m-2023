#include<bits/stdc++.h>
using namespace std;
long long **n;
long long f(int a, int b, int c, int d){
if(b-a<8){
double t = 0;
	for(int i = 0; (a<i+1) && i < b; i++){
	   for(int j = 0; c <= j && j < d; j++){
t+=n[i][j];
  }
}
t = t/((b-a)*(d-c));
 return t;
	}
	future <long long> s1 = async(f,a,b/2,c,d/2);
	future <long long> s2 = async(f,a,b/2,c+d/2,d);
	future <long long> s3 = async(f,a+b/2,b,c,d/2);
	future <long long> s4 = async(f,a+b/2,b,c+d/2,d);
	int sum = s1.get()+s2.get()+s3.get()+s4.get();
	return sum;
}
int main(){
    int x;
	cin >> x;
	n = new long long*  [x];
	for(int i=0; i<x; i++){
		n[i] = new long long [x];
	}
for(int i=0; i<x; i++){
  for(int j=0; j<x; j++){
cin >> n[i][j];
		}
	}
	thread r( [&](){ cout<<f(0,x,0,x); } );
	r.join();
}