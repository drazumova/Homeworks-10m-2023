#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
using namespace std;
mutex mtx;
int cnt = 0;
promise <string> username;
void f1(){
	future <string> f = username.get_future();
	string s = f.get();
	cout << "Welcome, " << s;
}
long long fact(long long a){
	mtx.lock();
	long long fct = 1;
	for(int i = 1; i <= a; i++){
		fct*=i;
	}
	mtx.unlock();
	return fct;
}
/*void f2(){
	string s;
	cin >> s;
	username.set_value(s);
}*/

int main(){
	
	
/*	thread t2(f2);
	t2.join();
	thread t1(f1);
	t1.join();*/
	#define int long long
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	vector<future<int> > res(n);
	for(int i = 0; i < n; i++){
		arr[i] = rand() % s;
		
		res[i] = async(fact, arr[i]);
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " : " << res[i].get() << '\n';
		
		
	}
	
	
	
}
