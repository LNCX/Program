#define DEBUG
#include<bits/stdc++.h>
#define up(x,y) (f[x][k-1]+sum[x]-f[y][k-1]-sum[y])
#define low(x,y) (dist[x]-dist[y])
using namespace std;
const int maxn=20005;
int add[maxn],sum[maxn],dist[maxn];
int w[maxn],d[maxn],f[maxn][3],q[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&d[i]);
	for(int i=1;i<=n+1;i++)
	{
		add[i]=add[i-1]+w[i-1];
		sum[i]=sum[i-1]+add[i]*d[i-1];
		dist[i]=dist[i-1]+d[i-1];
		f[i][0]=sum[i];
	}
	/*for(int k=1;k<=2;k++)
	{
		memset(q,0,sizeof(q));
		int l=1,r=1;
		for(int i=1;i<=n+1;i++)
		{
			while(up(q[l],q[l+1])>=add[i]*low(q[l],q[l+1])&&l<r) l++;
			f[i][k]=f[q[l]][k-1]+sum[q[l]]-add[i]*dist[q[l]]+add[i]*dist[i]-sum[i];
			while(up(q[r-1],q[r])*low(q[r],q[i])<=up(q[r],q[i])*low(q[r-1],q[r])&&l<r) r--;
			q[++r]=i;
		}
	}*/
	for(int k=1;k<=2;k++)
	{
		for(int i=k+1;i<=n+1;i++)
		{
			int minx=0x3f3f3f3f;
			for(int j=k;j<i;j++)
				minx=min(f[j][k-1]+sum[i]-sum[j+1]-add[j+1]*(dist[i]-dist[j+1]),minx);
			f[i][k]=minx;
		}
	}
	printf("%d\n",f[n][2]);
	#ifdef DEBUG
	for(int i=1;i<=n+1;i++)
		cout<<f[i][2]<<endl;
	#endif
	return 0;
}
