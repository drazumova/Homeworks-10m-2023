#include<iostream>
#include<concepts>
using namespace std;

template<typename T>
concept printable = 
    requires(T a) {
        {a.ToString()} -> same_as<string>;
    };
template<printable U, printable T>
void print(U a, T b){
    string a_ = a.ToString();
    string b_ = b.ToString();
    cout << a_ << ' ' << b_;
}
struct a{
    int val;
    string ToString(){
        return "1";
    }
};
int main(){
	a x, y;
	x.val = 100;
	y.val = 50;
	print<a, int>(x, y);
}