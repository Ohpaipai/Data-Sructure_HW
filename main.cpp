#include"Bst.h"
int main() {
	Bst T;
	T.Insert(100);
	T.Insert(101);
	T.Insert(154);
	T.Insert(99);
	T.Insert(130);
	T.Insert(129);
	T.Insert(128);
	T.Insert(160);
	T.Insert(159);
	T.Insert(167);
	//T.Delete(160);
	cout <<"ans  "<< double(T.avg(2, 4)) << endl;

		T.traverslal(T.root);
	system("pause");
	return 0;
}