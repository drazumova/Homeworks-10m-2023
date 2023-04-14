#include <iostream>
#include <future>
#include <string>
#include <thread>
#include <random>
using namespace std;
unsigned long long fact(unsigned long long n){
    if(n < 0){ 
        return 0; 
    }
    if(n == 0){
        return 1; 
    }
    else{ 
        return n*fact(n-1);
    }
}
int main(){
    int n,s;
    cin >>n>>s;
    srand(s);
    vector<unsigned long long>random;
    //future ans[n];
    vector<future<unsigned long long>> anss;
    for(int i=0;i<n;i++){
        unsigned long long r=rand()%64;
        random.push_back(r);
        std::future<unsigned long long> ans = std::async(fact, r);
        //std::future<unsigned long long> ans = std::async(fact, rand());
        //anss.push_back(ans);
        anss.push_back(std::move(ans));
    }
    for(int i=0;i<n;i++){
        //cout<<random[i]<<" "<<ans[i].get();
        cout<<random[i]<<" : "<<anss[i].get()<<'\n';
    }
}