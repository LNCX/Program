#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int f[12885]={0},w[3505],c[3505];
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	for(int j=m;j>=w[i];j--)
		f[j]=max(f[j-w[i]]+c[i],f[j]);
	cout<<f[m]<<endl;
} 
