#include<iostream>
using namespace std;
int pell(int a)
{
	if(a==1||a==2) return a;
	else
	{
		int sum=0,a1=1,a2=2;
		for(int i=2;i<a;i++)
		{
			sum=(2*a2+a1)%32767;
			a1=a2;
			a2=sum;
		}
		return a2;
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		cout<<pell(a)<<endl;
	}
}
