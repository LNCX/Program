#include<iostream>
using namespace std;
int main()
{
	int ans=0,max=0;
	for(int i=1;i<=7;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a+b>8&&a+b>max) {ans=i;max=a+b;}
	}
	cout<<ans<<endl;
}
