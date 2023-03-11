
// Готовят в СССР космонавта для полёта на Солнце. Он спрашивает: "А как я выживу? Солнце ж горячее!"
// А ему отвечают: "В ЦК не дураки сидят - ночью полетишь!"
#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
#include<future>
#include<mutex>
#include<fstream>
using namespace std;
//fstream fin("input.txt");
vector<string> str1;

mutex mtx;
const int n1 = 5;
const int n2 = 5; // n1, n2 - количества строк в 1 и 2 файлах, k - длина
promise <string> prms[n2];
bool b = 0;
string subb(string s){
	string s1;
	for(int i = 1 ; i < s.size(); i++){
		s1 += s[i];
	}
	return s1;
}
string subf(string s){
	string s1;
	for(int i = 0; i < s.size() -1; i++){
		s1 += s[i];
	}
	return s1;
}

int f1(){
	ifstream fin("input1.txt");
	
	for(int i = 0; i < n1; i++){
		mtx.lock();
		string s;
		fin >> s;
		prms[i].set_value(s);
		mtx.unlock();
		
	}
}
void f2(){
	ifstream fin("input2.txt");
	
	for(int i = 0; i < n2; i++){
		mtx.lock();
		string s;
		fin >> s;
		future <string> s2 = prms[i].get_future();
		string s1 = s2.get();
		if(subb(s1) == subf(s))
		str1.push_back(s1 + ' ' + s);
		mtx.unlock();
	}
	
}

int main(){
	thread t1(f1);
	t1.join();
	thread t2(f2);
	t2.join();
	for(int i = 0; i < str1.size(); i++){
		cout << str1[i] << '\n';
	}
}