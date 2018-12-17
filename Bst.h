#pragma once
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
	int leftSide;
	friend class Bst;
public:
	TreeNode() :leftchild(0), rightchild(0), parent(0), key(0),leftSide(0) {};
	TreeNode(int a,int b):leftchild(0), rightchild(0), parent(0), key(a),leftSide(b) {};
	TreeNode(int a) :leftchild(0), rightchild(0), parent(0), key(a), leftSide(0) {};

	int GetKey() { return key; }
	void setkey(int a) { key = a; }
	int Getleftside() { return leftSide; }
	void setLeftside(int a) { leftSide = a; }

};

class Bst {
public: TreeNode* root;
private:
	
	int ans = 0;
	int now = 0;
	TreeNode* FindRightsubtreesmallest(TreeNode *current) {
		TreeNode *findnode = new TreeNode;
		if (current->rightchild == NULL) return current;
		else findnode = current->rightchild;
		while (findnode->leftchild != NULL)
		{
			findnode = findnode->leftchild;

		}
		return findnode;
	}
	TreeNode *GetTheLeftNode() {
		TreeNode *returnNode = new TreeNode;
		returnNode = root;
		while (returnNode->leftchild != NULL)
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
	void traverslalforavg(TreeNode *current,const int start,const int end) {
		
		if (!current || current == NULL) return;
		traverslalforavg(current->leftchild, start,end);
		if (now >= start && now <= end) {
			ans += current->key;
		}
		now++;
		//cout << current->key << "   " << current->leftSide << endl;
		traverslalforavg(current->rightchild, start, end);
		


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
		TreeNode *mynode = new TreeNode(key);

		tem = root;
		int countleftside = 0;
		while (tem != NULL) {
			findnode = tem;
			if (mynode->key < tem->key) {
				//新增
				tem->leftSide++;
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
		else if (mynode->key<findnode->key)
		{

			
			findnode->leftchild = mynode;
			
		}
		else {
			
			findnode->rightchild = mynode;
			
		}

	}


	void Delete(int key) {
		TreeNode *deletenode = Search(key);
		if (deletenode == NULL) {
			cout << "Not find this node" << endl;
		}
		else {

			if (deletenode->leftchild == NULL&&deletenode->rightchild == NULL) {//都沒有孩子
				TreeNode *tem = deletenode;
				while (1)
				{
					if (tem== root) break;
					if (tem->parent->leftchild == tem) tem->parent->leftSide -= 1;

					tem = tem->parent;

				}
				if (deletenode->parent->leftchild == deletenode) deletenode->parent->leftchild = NULL;
				else deletenode->parent->rightchild = NULL;
				delete deletenode;
				deletenode = 0;
				
			}
			else if (deletenode->leftchild == NULL&&deletenode->rightchild != NULL) { //右邊有
				TreeNode *tem = deletenode;
				while (1)
				{
					if (tem == root) break;
					if (tem->parent->leftchild == tem) tem->parent->leftSide -= 1;

					tem = tem->parent;
				}
				if (deletenode->parent->leftchild == deletenode) deletenode->parent->leftchild = deletenode->rightchild;
				else deletenode->parent->rightchild = deletenode->rightchild;


				delete deletenode;
				deletenode = NULL;



			}
			else if(deletenode->leftchild!=NULL&&deletenode->rightchild==NULL){ //左邊有
				TreeNode *tem = deletenode;
				while (1)
				{
					if (tem == root) break;
					if (tem->parent->leftchild == tem) {
						tem->parent->leftSide -= 1;
					}

					tem = tem->parent;
				}
				if (deletenode->parent->leftchild == deletenode) deletenode->parent->leftchild =deletenode->leftchild;
				else deletenode->parent->rightchild = deletenode->leftchild;
				
				
				delete deletenode;
				deletenode=NULL;

			



			}
			else if (deletenode->leftchild != NULL&&deletenode->rightchild != NULL) { //兩邊都有	
				
				TreeNode *replace = FindRightsubtreesmallest(deletenode);
				TreeNode *tem = replace;
				while (1)
				{
					if (tem == root) break;
					if (tem->parent->leftchild == tem) {
						tem->parent->leftSide -= 1;
					}

					tem = tem->parent;
				}
				deletenode->key = replace->key;
				if (replace->parent->leftchild == replace) replace->parent->leftchild = NULL;
				else replace->parent->rightchild = NULL;
				delete replace;
				replace = NULL;

			}
		}

	}

	void traverslal(TreeNode *current) {
		
		if (!current||current==NULL) return;
		traverslal(current->leftchild);
		cout << current->key <<"   "<<current->leftSide<< endl;
		traverslal(current->rightchild);


	}

	

	double avg(int l, int u) {
		ans = 0;
		now=0;
		traverslalforavg(root, l, u);
		cout << ans << endl;
		int div = (u - l + 1);
		double	returnans = (double(ans) / double(div));
	return	returnans;
	}
	


};