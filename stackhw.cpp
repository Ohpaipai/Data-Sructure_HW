#include<iostream>
#include<vector>
#include<string>
#define N 10
using namespace std;

typedef struct MyStruct
{
	int x;
	int y;
}location;
string word;//my mapword
vector<location>mylocation; 
char mapinwordgame[N][N]; //map
bool used[N][N]; //map is uesd?
string dic; //mu input word
bool isfind; 
void FindPattern(string ,char);
bool isoutside(int,int);
bool isoutsideOfReused(int, int);
void gameing(int , int , int);
void gameingOfReused(int, int, int);
int main() {
	//initial
	isfind = false;
	word.clear();
	mylocation.clear();
	dic.clear();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			used[i][j] = false;
		}
	}
	cout << "please input 10*10 char word" << endl;
	cin >> mapinwordgame[0][0];
	
		
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0) {}
			else
			{
				cin >> mapinwordgame[i][j];
			}
		}
	}
		while (true)
		{
			//initial
			isfind = false;
			word.clear();
			mylocation.clear();
			dic.clear();
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					used[i][j] = false;
				}
			}

			//input
			cout << "please input what word you want to find & can'reused if can input 1 if not input 0,if you want to leave input 2" << endl;
			char r;
			cin >> dic;
			if ( dic=="2") {
				break;
			}
			cin >> r;
			if (r == '2') break;
			//to find the first word of the dic in my map
			for (int y = 0; y < N; y++)
			{
				for (int x = 0; x < N; x++)
				{
					if (mapinwordgame[y][x] == dic[0]) {
						mylocation.clear();
						isfind = false;
						used[y][x] = true;
						location tem;
						tem.y = y;
						tem.x = x;
						mylocation.push_back(tem);
						word.push_back(mapinwordgame[y][x]);
						FindPattern(dic, r);
						used[y][x] = false;
						word.pop_back();
						if (!isfind) mylocation.pop_back();
						if (isfind) break;
					}

				}
				if (isfind) break;
			}


			if (r == '0') {
				cout << "Case 2 :	patt:	" << dic << endl;
				cout << "		    reused:False" << endl;
				if (isfind) {
					cout << "		    Output:";
					for (int i = 0; i < mylocation.size(); i++)
					{
						cout << "(" << mylocation[i].y << "," << mylocation[i].x << ")";
					}
				}
				else {
					cout << "		    Output:no match";
				}
				cout << endl;
			}
			else if (r == '1') {
				cout << "Case 1 :	patt:	" << dic << endl;
				cout << "		    reused:True" << endl;
				if (isfind) {
					cout << "		    Output:";
					for (int i = 0; i < mylocation.size(); i++)
					{
						cout << "(" << mylocation[i].y << "," << mylocation[i].x << ")";
					}
				}
				else {
					cout << "		    Output:no match";
				}
				cout << endl;
			}
			else cout << "wrong" << endl;




		}



		system("pause");

	
}

//pattern
void FindPattern(string pitt, char reuesd){
	if (reuesd == '0') {
		gameing(mylocation[0].y, mylocation[0].x, 0);
		
	}
	else if (reuesd == '1') {
		gameingOfReused(mylocation[0].y, mylocation[0].x, 0);
	}
	else {
		cout << "u are not input 1 or 0" << endl;
	}
}

//edge or used?
bool isoutside(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N || used[y][x]) return true;
	else return false;
}

//edge
bool isoutsideOfReused(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N) return true;
	else return false;
}

//find word in map can used
void gameing(int y, int x, int wherechar){
	if (isfind) return;
	if (word == dic) {
		isfind = true;
	}
	if (isfind) return;
	x = x + 1;//right
	if (!isoutside(x,y)) {
		if (word.length() + 1 <= dic.length())
		{
			
			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				used[y][x] = true;
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameing(y, x, wherechar + 1);
				used[y][x] = false;
				word.pop_back();
				if(!isfind) mylocation.pop_back();
			}
		}
	}
	if (isfind) return;
	x = x - 2;//left
	if (!isoutside(x,y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				used[y][x] = true;
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameing(y, x, wherechar + 1);
				used[y][x] = false;
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
	if (isfind) return;
	x = x + 1;
	y = y - 1;//up
	if (!isoutside(x,y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				used[y][x] = true;
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameing(y, x, wherechar + 1);
				used[y][x] = false;
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
	if (isfind) return;
	y = y + 2;//down
	if (!isoutside(x, y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				used[y][x] = true;
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameing(y, x, wherechar + 1);
				used[y][x] = false;
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
}


//find word in map can used
void gameingOfReused(int y, int x, int wherechar) {
	if (isfind) return;
	if (word == dic) {
		isfind = true;
	}
	if (isfind) return;
	x = x + 1;//right
	if (!isoutsideOfReused(x, y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameingOfReused(y, x, wherechar + 1);
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
	if (isfind) return;
	x = x - 2;//left
	if (!isoutsideOfReused(x, y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameingOfReused(y, x, wherechar + 1);
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
	if (isfind) return;
	x = x + 1;
	y = y - 1;//up
	if (!isoutsideOfReused(x, y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameingOfReused(y, x, wherechar + 1);
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
	if (isfind) return;
	y = y + 2;//down
	if (!isoutsideOfReused(x, y)) {
		if (word.length() + 1 <= dic.length())
		{

			if (mapinwordgame[y][x] == dic[wherechar + 1]) {
				word.push_back(mapinwordgame[y][x]);
				location tem;
				tem.y = y;
				tem.x = x;
				mylocation.push_back(tem);
				gameingOfReused(y, x, wherechar + 1);
				word.pop_back();
				if (!isfind) mylocation.pop_back();
			}
		}
	}
}
