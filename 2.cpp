#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

    
template<typename t_elem>
t_elem sum(vector<t_elem> a){
    
    t_elem sm = a[0];
    
    for(int i = 1; i < a.size(); i++){
        sm = sm + a[i];
    }
    return sm;
}
template<typename t_elem>
t_elem sum(t_elem a){
    
    return a;
}
template<typename t_elem>
t_elem sum(set<t_elem> a){
    
    t_elem sm = *(a.begin());
    
    //auto itr;
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        sm = sm + (*itr);
    }
    
    return sm - (*a.begin());
}

int main(){
    int a1 = 10;
    vector<string> a2 {"1", "2", "3"};
    set<double> a3 {1.5, 2.0};

    cout << sum(a1); // 10
    cout << sum<string>(a2); // "123"
    cout << sum<double>(a3); // 3.5
}