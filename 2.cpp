#include<iostream>
#include<vector>
using namespace std;
template<typename T>
struct Node{
	
	public:
		T val;
		Node* r;
		Node* l;
		Node(T v){
			val = v;
			r = NULL;
			l = NULL;
		}
		
};
template<typename T>
class Btree{
	Node<T>* root;
	void add(Node<T>* newnode){
		Node<T>* ptr = root;
		while(1){
			if(ptr -> val >= newnode -> val && ptr -> l == NULL){
				ptr -> l = &newnode;
				return;
			}
			if(ptr -> val <= newnode -> val && ptr -> r == NULL){
				ptr -> r = &newnode;
				return;
			}
			if(ptr -> val <= newnode -> val && ptr -> r != NULL){
				ptr = ptr -> r;
				continue;
			}
			if(ptr -> val >= newnode -> val && ptr -> l != NULL){
				ptr = ptr -> l;
				continue;
			}
		}
	}
	bool find(T search){
		Node<T>* ptr = root;
		while(1){
			if(ptr -> val == search){
				return 1;
			}
			if(ptr -> val < search && ptr -> r == NULL){
				return 0;
			}
			if(ptr -> val > search && ptr -> l == NULL){
				return 0;
			}
			if(ptr -> val > search && ptr -> l != NULL){
				ptr = ptr -> l;
				continue;
			}
			if(ptr -> val < search && ptr -> r != NULL){
				ptr = ptr -> r;
				continue;
			}
		}
	}
	
};

int main(){
	
}