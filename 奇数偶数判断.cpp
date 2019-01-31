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
			cout<<b<<"是偶数"<<endl;
			else
			cout<<b<<"是奇数"<<endl;
		}
		else
		cout<<"Error"<<endl;
	}
}
