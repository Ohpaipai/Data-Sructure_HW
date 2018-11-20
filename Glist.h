#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename A>
 struct Node
{
	
	 A coef;
	 A ex;
	 A ey;
	 A ez;
};

template <class T>
struct GenListNode              
{
	int utype=0;               //  1�����P�@�h��list   
	GenListNode<T> *tlink=NULL;   //utype 0�O�ڪ��Y �û����V�Ĥ@�Ӧa�� 1 �ɬ��P�@�h 2�� ���U�@�h
	 struct MyStruct
	{
		Node<T> data;
		GenListNode<T> *hlink = NULL;
	}info;
};

string choose;
int a, b, c, d;
bool firstof = true;
GenListNode<int> initial;
GenListNode<int> firstnode;

void Mulf( int _ex, int _ey, int _ez) {
	GenListNode<int> *usethis;
	initial = firstnode;
	usethis =&initial;
	while (usethis->tlink != NULL)
	{
		//cout<<usethis->tlink->info.data.coef<<endl;
		if (usethis->utype == 1) { //�P�@�h
			usethis->tlink->info.data.ex += _ex;
			usethis->tlink->info.data.ey += _ey;
			usethis->tlink->info.data.ez += _ez;
			usethis->tlink = usethis->tlink->tlink;
		}
		else if(usethis->utype==2){
			usethis->tlink = usethis->info.hlink;//���ګ��Щ��U�h����
		}
		else {
			break;
		}
	}
}
int refCoeff(int _ex, int _ey, int _ez)
{
	
	GenListNode<int> *usethis;
	initial = firstnode;
	usethis = &initial;
	int ans=0;
	while (usethis->tlink != NULL)
	{
		//cout << usethis->tlink->info.data.coef << endl;
		if (usethis->utype == 1) { //�P�@�h
			if (usethis->tlink->info.data.ex == _ex &&
				usethis->tlink->info.data.ey == _ey &&
				usethis->tlink->info.data.ez == _ez)
			{
				ans = usethis->tlink->info.data.coef;
				break;
			}
			else {
				usethis->tlink = usethis->tlink->tlink;
			}
		}
		else if (usethis->utype == 2) {
			usethis->tlink = usethis->info.hlink;//���ګ��Щ��U�h����
		}
		else {
			break;
		}
	}
	return ans;
	
}