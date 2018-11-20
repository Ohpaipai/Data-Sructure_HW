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
	int utype=0;               //  1為往同一層的list   
	GenListNode<T> *tlink=NULL;   //utype 0是我的頭 永遠指向第一個地方 1 時為同一層 2時 為下一層
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
		if (usethis->utype == 1) { //同一層
			usethis->tlink->info.data.ex += _ex;
			usethis->tlink->info.data.ey += _ey;
			usethis->tlink->info.data.ez += _ez;
			usethis->tlink = usethis->tlink->tlink;
		}
		else if(usethis->utype==2){
			usethis->tlink = usethis->info.hlink;//讓我指標往下層移動
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
		if (usethis->utype == 1) { //同一層
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
			usethis->tlink = usethis->info.hlink;//讓我指標往下層移動
		}
		else {
			break;
		}
	}
	return ans;
	
}