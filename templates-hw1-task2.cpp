#include <iostream>
#include<vector>

using namespace std;

template<typename T>
class Node {
    public:
    T value;
    Node * left, * right;
    
    Node(T x) {
        value = x;
        left = right = 0;
    }
};
    
template<typename T>    
class Tree {
    private:
    Node<T>* root;
    
    void add_b(Node<T>* tree, T x) {
        if(tree -> value > x) {
            if(tree -> left == 0) {
                tree -> left = new Node<T>(x);
            } else {
                add(tree -> left, x);
            }
        }
        else {
            if(tree -> right == 0) {
                tree -> right = new Node<T>(x);
            } else {
                add(tree -> right, x);
            }
        }
    }
    
    bool find_b(Node<T>* tree, T x) {
        if (tree->value == x)
        return (bool)tree;
        if (tree->value > x) {
            if (tree->left == 0) return 0;
            return (bool)find(tree->left, x);
        } else {
            if (tree->right == 0) return 0;
            return (bool)find(tree->right, x);
        }
    }
    
    public:
    Tree(Node<T>* r) {
        root = r;
    }
    
    void add(T x) {
        add_b(root, x);
    }
    
    bool find(T x) {
        return find_b(root, x);
    }

};

 

int main() {
}