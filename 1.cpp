#include<iostream>
#include<vector>
using namespace std;
template <typename T>
T vector_sum (vector<T> a){
	T sum = a[0];
	for(int i = 1; i < a.size(); i++){
		sum += a[i];
	}
	return sum;
}
int main(){
	/*
	vector<int> a(10, 10);
	cout << vector_sum<int>(a) << '\n';
	vector<string> b(10, "AAA");
	cout << vector_sum<string>(b) << '\n';
	*/
}