#include<iostream>
using namespace std;
int f(int n,int m)
{
	if(n==0||m==1) return 1;
	if(n<m) return f(n,n);
	return f(n,m-1)+f(n-m,m);
}
int main()
{
	int x;
	cin>>x;
	while(x--)
	{
		int n,m;
		cin>>n>>m;
		cout<<f(n,m)<<endl;
	}
}
