#include <iostream>
#include <future>
#include <string>
#include <thread>
using namespace std;
void f(std::promise<string> prms){
    string username;
    cin>>username;
    prms.set_value(username);
    //std::future<int> f_result = prms.get_future(username);
}
void yw(std::future<string>f_result){
    string username = f_result.get();
    cout<<"Добро пожаловать,"<<username<<"!";
}
int main(){
    std::promise<string> prms; 
    std::future<string> f_result = prms.get_future();
    std::thread t1(f, std::move(prms));
    std::thread t2(yw, std::move(f_result));
    t1.join();
    t2.join();
}
