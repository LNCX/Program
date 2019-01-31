#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a=n,b=0;
	for (int s=1;m>0;s++,a--)
		m-=b=min(s,m);
	for(int i=1;i<a;i++)
		cout<<i<<' ';
	cout<<a+b<<' ';
	for(int i=n;i>=a;i--)
		if(i!=a+b)
			cout<<i<<' ';
}
