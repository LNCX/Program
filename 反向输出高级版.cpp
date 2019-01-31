#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	while(1)
	{
		cout<<"input:";
		long int x;
		int y;
		cin>>x;
		cin>>y;
		int a[y];
		for(int i=y-1;i>=0;i--)
		{
			int m=0; 
			a[i]=x/pow(10,i);
			m+=a[i]*pow(10,i);
			x-=m;
		}
		cout<<"output:";
		for(int i=0;i<=y-1;i++)
		cout<<a[i];
		cout<<endl;
	}
}
