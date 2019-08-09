#include<bits/stdc++.h>
#define N 10005
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	long long w[N],c[N],f[N]={0};
	for(int i=1;i<=n;i++)	scanf("%ld%ld",&c[i],&w[i]);
	for(int i=1;i<=n;i++)
	for(int v=w[i];v<=m;v++)
		f[v]=max(f[v],f[v-w[i]]+c[i]);
	cout<<f[m]<<endl;
} 
