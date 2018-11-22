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
public:
	Bst() :root(0) {};

	TreeNode* Search(int key) {
		TreeNode *current = root;//����ڪ��}�Y
		while (current != NULL && key != current->key) {
			if (key < current->key) {//�p�� �������
				current = current->leftchild;
			}
			else {//�j�� ���k��
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
				tem = tem->leftchild;//�p�������䨫
			}
			else 
			{
				tem = tem->rightchild;//�j�󩹥k��
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
			if (deletenode->leftchild == NULL&&deletenode->rightchild == NULL){//��case
				reallydelete = deletenode;
			}
			else {
				reallydelete = FindRightsubtreesmallest(deletenode);
			}


			if (reallydelete->leftchild != NULL) { //��X��l
				deletechild = reallydelete->leftchild;
			}
			else deletechild = reallydelete->rightchild;

			if (deletechild != NULL) //��Ĥl���^�h
			{
				deletechild->parent = reallydelete->parent;
			}

			if (reallydelete->parent == NULL) { //���p�R����root �⥦��@root
				this->root = deletechild;
			}
			else if (reallydelete == reallydelete->parent->leftchild) { //���]���쥻������Ĥl ��deletechild���W�R�������N
				reallydelete->parent->leftchild = deletechild;
			}
			else {
				reallydelete->parent->rightchild = deletechild;
			}

			if (reallydelete != deletenode) {// ��key���L
				deletenode->key = reallydelete->key;
			}

			delete reallydelete;
			reallydelete = 0;

		}
		
	}

};