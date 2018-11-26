#include <iostream>
#include <string>

using namespace std;


class Bst;
class TreeNode {
private:
	TreeNode *leftchild;
	TreeNode *rightchild;
	TreeNode *parent;
	int key;
	friend class Bst;
public:
	TreeNode() :leftchild(0), rightchild(0), parent(0), key(0) {};
	TreeNode(int a) :leftchild(0), rightchild(0), parent(0), key(a) {};

	int GetKey() { return key; }
	void setkey(int a) { key = a; }

};

class Bst {
private:
	int ans = 0;
	int sum = 0;
	bool find = false;
	TreeNode* root;
	TreeNode* FindRightsubtreesmallest(TreeNode *current) {
		TreeNode *findnode = new TreeNode;
		if (current->rightchild == NULL) return current;
		else findnode = current->rightchild;
		while (findnode->leftchild!=NULL)
		{
			findnode = findnode->leftchild;
			
		}
		return findnode;
	}
	TreeNode *GetTheLeftNode() {
		TreeNode *returnNode = new TreeNode;
		returnNode = root;
		while (returnNode->leftchild!=NULL)
		{
			returnNode = returnNode->leftchild;
		}
		return returnNode;
	}
	TreeNode *GetTheRightNode() {
		TreeNode *returnNode = new TreeNode;
		returnNode = root;
		while (returnNode->rightchild != NULL)
		{
			returnNode = returnNode->rightchild;
		}
		return returnNode;
	}
	void traverslal(TreeNode *current,const int num) {
		if (find) return;
		if (!current) return;
		traverslal(current->leftchild,num);
		cout << current->key << endl;
		sum += current->key;
		if (sum >= num&&!find) {
			ans = current->key;
			find = true;
			return;
		}
		traverslal(current->rightchild,num);

		
	}
public:
	Bst() :root(0) {};

	TreeNode* Search(int key) {
		TreeNode *current = root;//先到我的開頭
		while (current != NULL && key != current->key) {
			if (key < current->key) {//小於 往左邊找
				current = current->leftchild;
			}
			else {//大於 往右邊
				current = current->rightchild;
			}
		}
		return current;
	}

	void  Insert(int key) {
		TreeNode *findnode = 0;
		TreeNode *tem = 0;
		TreeNode *mynode=new TreeNode(key);

		tem = root;
		while (tem != NULL) {
			findnode =tem;
			if (mynode->key < tem->key) {
				tem = tem->leftchild;//小的往左邊走
			}
			else 
			{
				tem = tem->rightchild;//大於往右邊
			}
		}

		mynode->parent = findnode;

		if (findnode == NULL) {
			this->root = mynode;
		}
		else if(mynode->key<findnode->key)
		{
			findnode->leftchild = mynode;
		}
		else findnode->rightchild = mynode;
	}


	void Delete(int key) {
		TreeNode *deletenode = Search(key);
		if (deletenode == NULL) {
			cout << "Not find this node" << endl;
		}
		else {
			TreeNode *reallydelete = 0;
			TreeNode *deletechild = 0;
			if (deletenode->leftchild == NULL&&deletenode->rightchild == NULL){//分case
				reallydelete = deletenode;
			}
			else {
				reallydelete = FindRightsubtreesmallest(deletenode);
			}


			if (reallydelete->leftchild != NULL) { //抓出兒子
				deletechild = reallydelete->leftchild;
			}
			else deletechild = reallydelete->rightchild;

			if (deletechild != NULL) //把孩子接回去
			{
				deletechild->parent = reallydelete->parent;
			}

			if (reallydelete->parent == NULL) { //假如刪除為root 把它當作root
				this->root = deletechild;
			}
			else if (reallydelete == reallydelete->parent->leftchild) { //假設為原本的左邊孩子 把deletechild接上刪掉的取代
				reallydelete->parent->leftchild = deletechild;
			}
			else {
				reallydelete->parent->rightchild = deletechild;
			}

			if (reallydelete != deletenode) {// 把key給他
				deletenode->key = reallydelete->key;
			}

			delete reallydelete;
			reallydelete = 0;

		}
		
	}

	int Minmap(int num) {
		int PlusAll = 0;
		TreeNode* mynode = new TreeNode;
		mynode = root;
		bool find = false;
	    sum = 0;
		ans = 0;
		find = false;
		traverslal(mynode, num);
		return ans;
	}


};