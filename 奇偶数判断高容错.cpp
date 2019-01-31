#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		char com[100];
		int med[100];
		int i=0,flag=1;
		cin>>com;
		while(com[i]!=com[99])
		{
			switch(com[i])
			{
				case '1':
					med[i]=1;
					break;
				case '2':
					med[i]=2;
					break;
				case '3':
					med[i]=3;
					break;
				case '4':
					med[i]=4;
					break;
				case '5':
					med[i]=5;
					break;
				case '6':
					med[i]=6;
					break;
				case '7':
					med[i]=7;
					break;
				case '8':
					med[i]=8;
					break;
				case '9':
					med[i]=9;
					break;
				case '0':
					med[i]=0;
					break;
				default:
					flag=0;
			}
			i++;
		}
		if(flag==1)
		{
			if(med[i-1]%2==0)
				cout<<"该数是偶数"<<endl;
			else
				cout<<"该数是奇数"<<endl; 
		}
		else
			cout<<"王丹颖和洪连凯"<<endl;
	}
}

