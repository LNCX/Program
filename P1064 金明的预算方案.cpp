#include<bits/stdc++.h>
using namespace std;
#define N 10005
int w[N],p[N],q[N],s[N][2],f[32005];
int main()
{
	int n,m,mid;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&w[i],&p[i],&q[i]);
		if(q[i])
			if(!s[q[i]][0]) s[q[i]][0]=i;
			else	s[q[i]][1]=i;
	}
	for(int i=1;i<=m;i++)
	for(int v=n;v>=w[i]&&!q[i];v--)
	{
		int maxx=0,sum[5]={0},x=s[i][0],y=s[i][1];
		if(v-w[i]-w[x]>=0)	    sum[1]=f[v-w[i]-w[x]]+w[i]*p[i]+w[x]*p[x];
		if(v-w[i]-w[y]>=0)	    sum[2]=f[v-w[i]-w[y]]+w[i]*p[i]+w[y]*p[y];
		if(v-w[i]-w[x]-w[y]>=0) sum[3]=f[v-w[i]-w[x]-w[y]]+w[i]*p[i]+w[x]*p[x]+w[y]*p[y];
		if(v-w[i]>=0)			sum[4]=f[v-w[i]]+w[i]*p[i];
		maxx=max(max(sum[1],sum[2]),max(sum[3],sum[4]));
		f[v]=max(f[v],maxx);
	}
	cout<<f[n]<<endl;
}
