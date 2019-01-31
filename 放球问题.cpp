#include<iostream>
using namespace std;
int f(int n,int m)
{
	if(n!=0&&m==0) return 0;
	if(n!=0&&m==1) return 1;
	if(n==m) return 1;
	if(n<m) return 0;
	return (m*f(n-1,m)+m*f(n-1,m-1));
}
int main()
{
	while(1)
	{
		int n,m;
		cin>>n>>m;
		cout<<f(n,m)<<endl;
	}
}
