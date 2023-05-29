#include <iostream>
#include <string>
#include <concepts>
template<typename T, typename U>
concept HasToString = requires(T t,U u){
    {t.toString() } -> std::convertible_to<std::string>;
    {u.toString() } -> std::convertible_to<std::string>;
};
template<typename T,typename U>
void print(T a, U b) {
    std::cout<<a.toString()<< " " <<b.toString() <<std::endl;
}

class MyClass1 {
public:
    std::string toString() {
        return "MyClass1";
    }
};

class MyClass2 {
public:
    std::string toString() {
        return "MyClass2";
    }
};
int main() {
    MyClass1 obj1;
    MyClass2 obj2;
    print(obj1, obj2);
    return 0;
}