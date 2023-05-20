#include<iostream>
#include<vector>

#include<cstdlib>
using namespace std;
template <typename T>
T* _Alloc(T new_val){
	T* a = new T;
	(*a) = new_val;
	return a;
}
int main(){
	
}