#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		float a;
		cin>>a;
		int b=(int)a;
		if(a==b)
		{
			if(b%2==0)
			cout<<b<<"��ż��"<<endl;
			else
			cout<<b<<"������"<<endl;
		}
		else
		cout<<"Error"<<endl;
	}
}
