#include<bits/stdc++.h>
using namespace std;
mutex mtx;
mutex mtx2;
condition_variable cv;
vector<long long> a; 
long long w = 0;
void l1(){
	unique_lock<mutex> lck(mtx);
	while(true){
		this_thread::sleep_for(chrono::milliseconds(900));
		a.push_back(rand());
		cv.notify_all();
		cv.wait(lck);
	}
}

void l2(){
	unique_lock<mutex> lck(mtx);
	while(true){
		this_thread::sleep_for(chrono::milliseconds(1000));
		for(int i = 0; i < a.size(); i++){
			if(a[i]>w){
				cout <<"maximum changed" << " ";
				w = a[i];
			}
		}
		cout << w << endl;;
		cv.notify_all();
		cv.wait(lck);
	}
} 

int main(){
	thread th1(l1);
	thread th2(l2);
	th1.join();
	th2.join();
}