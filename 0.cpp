#include <iostream>
#include <thread>
#include <mutex>
//#include <promise>
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
void f2(){
	string s;
	cin >> s;
	username.set_value(s);
}

int main(){
	
	
	thread t2(f2);
	t2.join();
	thread t1(f1);
	t1.join();
	
	
	
}
