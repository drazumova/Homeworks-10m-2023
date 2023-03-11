#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
#include<future>
#include<mutex>
using namespace std;
vector<int> arr;
mutex mtx;
int n;
int a;
int f(int begin, int end){
	//mtx.lock;
	if(end - begin == 2){
		return arr[begin]+arr[begin+1]+arr[end];
	}
	if(end - begin == 1){
		return arr[begin]+arr[end];
	}
	if(end == begin){
		return arr[begin];
	}
	future <int> sum1 = async(f, begin, begin - (begin - end)/3);
	future <int> sum2 = async(f, begin - (begin - end) / 3 + 1, begin - 2*(begin - end) / 3);
	future <int> sum3 = async(f, begin - 2*(begin - end) / 3 + 1, end);
	int sum = sum1.get() % a + sum2.get() % a + sum3.get() % a;
	//mtx.unlock;
	return sum;
}


int main(){
	cin >> n;
	cin >> a;
	arr.resize(n, 0);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	future <int> s = async(f, 0, n-1);
	//future <int> s = async(g);
	cout << s.get() % a;
	
}