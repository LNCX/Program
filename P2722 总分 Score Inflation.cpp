#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	long long w[maxn],c[maxn],f[maxn]={0};
	for(int i=1;i<=n;i++)	scanf("%ld%ld",&c[i],&w[i]);
	for(int i=1;i<=n;i++)
	for(int v=w[i];v<=m;v++)
		f[v]=max(f[v],f[v-w[i]]+c[i]);
	cout<<f[m]<<endl;
} 
