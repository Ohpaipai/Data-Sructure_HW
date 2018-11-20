#include"GList.h"


int main() {
	
	
	initial.utype = 1;
	while (cin >> a >> b >> c >> d) {
		if (a == 0 && b == 0 && c == 0 && d == 0)
		{
			break;
		}
		if (firstof) {
			GenListNode<int> *first=new GenListNode<int>;
		
			first->info.data.coef = a;
			first->info.data.ex = b;
			first->info.data.ey = c;
			first->info.data.ez = d;
			first->utype = 1;
			initial.tlink = first;
			firstnode = initial;
			firstof = false;
			
		}
		else{
			GenListNode<int> *tem = new GenListNode<int>;
	
			bool smae = false;
			tem->utype = 1;
			tem->info.data.coef = a;
			tem->info.data.ex = b;
			tem->info.data.ey = c;
			tem->info.data.ez = d;
			GenListNode<int> *usethis=NULL;
			usethis = &initial;
			while (usethis->tlink != NULL)
			{
				if (usethis->tlink->info.data.ex == b &&
					usethis->tlink->info.data.ey == c &&
					usethis->tlink->info.data.ez == d)
				{
					usethis->tlink->info.data.coef += a;
					smae = true;
					break;
				}
				else {
					usethis = usethis->tlink;
				}
			}
			if (!smae)
			usethis->tlink = tem;

			
			
		}
	}



	/*GenListNode<int> *usethis;
	usethis = &initial;
	while (usethis->tlink != NULL)
	{
		cout << usethis->tlink->info.data.coef << endl;
		usethis= usethis->tlink;
	}*/




	while (cin >> choose)
	{
		string up = "";
		for (int i = 0; i < choose.length(); i++)
		{
			up += toupper(choose[i]);
		}
		if (up == "REFCOEFF"){
			cin >> b >> c >> d;
			cout<<refCoeff(b, c, d) << endl;
		}
		else if (up == "MULF"){
			cin >> b >> c >> d;
			Mulf( b, c, d);
		}
		else {
			cout << "undefined , please input again" << endl;
		}
	}

	return 0;
}
