#include <iostream>
#include<string>

using namespace std;


class Dog {
  string name; 
  int age;
  
  public: 
    Dog(string n, int a) {
        name = n; age = a;
    }
    string print() {
        string l = "Dog name: ";
        l += name;
        l += " dog age: ";
        std::string s = std::to_string(age);
        l += s;
        return l;
    }
};
class Cat {
  string name; 
  int age;
  
  public: 
    Cat(string n, int a) {
        name = n; age = a;
    }
    string print() {
        string l = "Cat name: ";
        l += name;
        l += " cat age: ";
        std::string s = std::to_string(age);
        l += s;
        return l;
    }
};

template <typename U, typename V>
concept N = requires(U a, V b) {
    { a.print() } -> std :: convertible_to <std :: string>;
    { b.print() } -> std :: convertible_to <std :: string>;
};

template <typename U, typename V>
void print_all (U a, V b) requires N<U, V> {
    cout << a.print() << endl;
    cout << b.print() << endl;
};

int main() {
    Cat cat("Jhon", 2);
    Dog dog1("Norton", 3);
    Dog dog2("Mart", 1);
    
    print_all<Cat, Dog>(cat, dog1);
    print_all<Dog, Dog>(dog1, dog2);
    
}
