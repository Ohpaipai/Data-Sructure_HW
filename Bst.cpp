#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::cout;
using std::endl;

class Bst;
class TreeNode {
private:
	TreeNode *leftchild;
	TreeNode *rightchild;
	TreeNode *parent;
	int key;
	
	friend class Bst;
public:
	TreeNode() :leftchild(0), rightchild(0), parent(0), key(0){};
	TreeNode(int a) :leftchild(0), rightchild(0), parent(0), key(a) {};

	int GetKey() { return key; }              
  
	
};

class Bst {
private:
	TreeNode* root;
public:
	Bst() :root(0) {};
	TreeNode* Search(int KEY){
		TreeNode *current = root;              
		while (current != NULL && KEY != current->key) { 
														  
			if (KEY < current->key) {
				current = current->leftchild;  
			}
			else {
				current = current->rightchild; 
			}
		}
		return current;
	}
	TreeNode* Insert(int KEY) {
		TreeNode *father;
		TreeNode *tem;
		TreeNode *mynode(KEY);
	}

};