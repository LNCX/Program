#include<bits/stdc++.h>
#define maxn 30000
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int c[maxn],w[maxn],f[maxn]={0};
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	for(int v=m;v>=w[i];v--)
		f[v]=max(f[v],f[v-w[i]]+c[i]);
	cout<<f[m]<<endl;
}

