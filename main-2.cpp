#include <iostream>
#include<vector>
using namespace std;
template<typename T>
class Node{
    public:
    T value;
    Node * next;
    Node(T val){
        value=val;
        next=nullptr;
    }
};

template<typename T>
class Tree{
    private:
    Node<T>* root;
    void add(Node<T>* node, T val) {
        if (node==nullptr) {
            node=new Node<T>(val);
        } 
        else{
            add(node->next, val);
        }
    }
    bool find(Node<T>* node, T val){
        if (node == nullptr) {
            return false;
        }
        else if (node->value == val) {
            return true;
        }
        else {
            return find(node->next, val);
        }
    }   
    public:
    Tree(Node<T>*n ) {
        root=n;
    }
    void add(T val) {
        add(root, val);
    }
    bool find(T val){
        return find(root, val);
    }
};
int main(){}