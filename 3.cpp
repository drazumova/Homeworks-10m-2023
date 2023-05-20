#include<iostream>
#include<vector>
#include<set>
#include<concepts>
#include<cmath>
using namespace std;

template<typename T>
T combine(T a, T b){
	return a + b; // просто какая-то заглушка
}
template<typename T>
concept norm =
    requires(T a, T b) {
        {combine<T>(a, b)} -> same_as<T>;
    };


template<norm T>
class stree{ // В ДО 0-й элемент не имееет смысла, combine от всего - это st[1], поиск написать не успел 
	T neutral; // это нейтральный элемент
	vector<T> st;
	int N;
	stree(vector <T> v1, T neut){
		neutral = neut;
		int n = log(v1.size())/log(2) + (int)(pow(2, (int)log(v1.size() ) ) == v1.size());
		st.resize(pow(2, n));
		v1.resize(pow(2, n), neutral);
		N = pow(2, n);
		for(int i = N / 2; i < N; i++){
			st[i] = v1[i - N / 2];
		}
		for(int i = N / 2; i >= 1; i--){
			st[i] = combine<T>(st[i * 2] + st[i * 2 + 1]);
		}
	}
	
	void change(T val, int index){
		st[index + N / 2] = val;
		for(int i = N / 2; i >= 1; i--){
			st[i] = combine<T>(st[i * 2] + st[i * 2 + 1]);
		}
	}
	
};
int main(){
	
}