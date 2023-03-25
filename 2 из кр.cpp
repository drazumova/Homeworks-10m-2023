#include<bits/stdc++.h>
using namespace std;
vector<long long> v; 
condition_variable t;
mutex mtx;
mutex mtx1;
long long  x;
void f(){
unique_lock<mutex> lck(mtx);
  while(true){
v.push_back(rand());
t.notify_all();
t.wait(lck);
	}
}
void g(){
unique_lock<mutex> lck(mtx);
long long x;
  while(true){
 for(int i = 0; i < v.size(); i++){
if(v[i]>x){
	x = v[i];
    cout <<"человекочитаемое сообщение" << " ";
	}
}
cout << x << endl;;
t.notify_all();
t.wait(lck);
	}
} 
int main(){
thread i(f);
thread j(g);
	i.join();
	j.join();
}