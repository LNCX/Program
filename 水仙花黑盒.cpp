#include<iostream>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	{
		if(a==0)
		break;
		if(a==153||a==370||a==371||a==407)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
}
