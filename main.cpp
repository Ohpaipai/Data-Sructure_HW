#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct MyStruct
{
	int name;
	int AT;
	int ST;
	int AWT;
	bool can = false;
	int detime = 0;
}Client;
queue<Client>line;
Client costumer[10];
bool less_int(Client a, Client b);
int main() {
	bool leave = false;
	int time = 0;
	int waittime = 0;
	bool head = true;
	bool nexttodo = true;
	while(1){
		int count = 0;
		while (!line.empty())
		{
			line.pop();
		}
		cout << "please input client information,if ur imformation is enough please input -1,if you want to leave please input -2" << endl;
		cout << "	" << "Arrival time" << "	" << "Service time" << "	" << "Allowable waiting time" << endl;
		while (1)
		{
			cout << "Client" << count + 1 << "  ";
			cin >> costumer[count].AT;
			if (costumer[count].AT == -1) {
				break;
			}
			else if (costumer[count].AT == -2) {
				leave = true;
				break;
			}
			else costumer[count].name = count;
			cin >> costumer[count].ST;
			if (costumer[count].ST == -1) {
				break;
			}
			else if (costumer[count].ST == -2) {
				leave = true;
				break;
			}
			else costumer[count].name = count;
			cin >> costumer[count].AWT;
			
			if (costumer[count].AWT == -1) {
				break;
			}
			else if (costumer[count].AWT == -2) {
				leave = true;
				break;
			}
			else costumer[count].name = count;

			count++;

			if (count >=10) {
				cout << "The number has reached the limit" << endl;
				break;
			}
						
		}
		if (!leave)
		{
			queue<Client>insertline;
			sort(costumer, costumer + count, less_int);
			time = costumer[0].AT;
			for (int i = 0; i < count; i++)
			{

				line.push(costumer[i]);
			}
			cout << "	" << "Served or not? " << "		" << "Departure time" << endl;
			Client tem = line.front();
				   line.pop();
				   costumer[tem.name].can = true;
				   time +=tem.ST;
				   costumer[tem.name].detime = time ;
			while (!line.empty())
			{
				
				if (line.size() == 1)//是否末端
				{
					if (insertline.empty())//是否空的
					{
						tem = line.front();
						line.pop();
						if (tem.AT + tem.AWT > time)//第一個人可以做
						{
							costumer[tem.name].can = true;
							if(time<tem.AT) time = tem.ST+tem.AT;
							else time += tem.ST;
							costumer[tem.name].detime = time;
						}
						
					}
					else
					{
						tem = line.front();
						line.pop();
						if (tem.AT < time){//時間是否已經超過
							while (!insertline.empty())
							{
								Client intem = insertline.front();
								insertline.pop();
								if (tem.AT + tem.AWT > time)//他還有時間做
								{
									if (intem.ST + time < tem.AWT + tem.AT)//可以做
									{
										costumer[intem.name].can = true;
										time += intem.ST;
										costumer[intem.name].detime = time;
									}
									else {//已經不能再插入做要不你自己沒得做了
										costumer[tem.name].can = true;
										if (time < tem.AT) time = tem.ST + tem.AT;
										else time += tem.ST;
										costumer[tem.name].detime = time;
										break;
									}

								}
							}
						}
						else {
							if (tem.AT + tem.AWT > time)//第一個人可以做
							{
								costumer[tem.name].can = true;
								if (time < tem.AT) time = tem.ST + tem.AT;
								else time += tem.ST;
								costumer[tem.name].detime = time;
							}
						}
					
					}
				}
				else
				{
					tem = line.front();
					line.pop();
					Client tem2 = line.front();
						if (tem.AT < time&&tem2.AT < time)//後兩位都到了
						{
							if ((time < tem.AWT + tem.AT))
							{
								if ((tem2.ST < tem.ST) && ((time + tem2.ST) < tem.AWT + time))//第二位你服務時間小於第一位
								{
									costumer[tem2.name].can = true;
									time += tem2.ST;
									costumer[tem2.name].detime = time;
									costumer[tem.name].can = true;
									time += tem.ST;
									costumer[tem.name].detime = time;
									line.pop();
								}
								else
								{
									if (tem.AT + tem.AWT > time)//第一個人可以做
									{
										costumer[tem.name].can = true;
										if (time < tem.AT) time = tem.ST + tem.AT;
										else time += tem.ST;
										costumer[tem.name].detime = time;
									}
									else //讓他到最後一個人前面
									{
										insertline.push(tem);
									}
								}
							}
							else //讓他到最後一個人前面
							{
								insertline.push(tem);
							}
							
						}
						else
						{
							if (tem.AT + tem.AWT > time)//第一個人可以做
							{
								costumer[tem.name].can = true;
								if (time < tem.AT) time = tem.ST + tem.AT;
								else time += tem.ST;
								costumer[tem.name].detime = time;
							}
							else //讓他到最後一個人前面
							{
								insertline.push(tem);
							}
						}

				}
			}
			for (int i = 0; i < count; i++)
			{
				cout << "Client" << i+1 << "    ";
				if (costumer[i].can) cout << "Yes				" << costumer[i].detime << endl;
				else  cout << "No	" << endl;
			}
		}
		else break;
	}
	system("pause");
}

bool less_int(Client a, Client b) {

	return b.AT > a.AT;

}
