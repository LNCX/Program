#include<bits/stdc++.h>
using namespace std;
const int N=13,M=2e3+5;
int t,n,m,f[N][1<<N],g[N][1<<N],a[N][N];
struct node
{
	int d[N],maxx;
	void pre()
	{
		maxx=0;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,d[i]);
	}
	bool operator<(const node &k) const
	{
		return maxx>k.maxx;
	}
}e[M];
int solve(int x,int s)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
			if(s&(1<<(j-1)))	
				res+=a[j][x];
		ans=max(res,ans);
		for(int j=n;j>=1;j--)
			a[j+1][x]=a[j][x];
        a[1][x]=a[n+1][x];
	}
	return ans;
}
void pre()
{
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&e[j].d[i]);
    for(int i=1;i<=m;i++)
        e[i].pre();
    sort(e+1,e+1+m);
    m=min(m,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=e[j].d[i];
    for(int i=1;i<=m;i++)
        for(int j=0;j<(1<<n);j++)
            g[i][j]=solve(i,j);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
        pre();
		for(int i=1;i<=m;i++)
			for(int j=0;j<(1<<n);j++)
			{
				f[i][j]=f[i-1][j];
				for(int k=j;k!=0;k=(k-1)&j)
					f[i][j]=max(f[i][j],f[i-1][j^k]+g[i][k]);
			}
		printf("%d\n",f[m][(1<<n)-1]);
	}
	return 0;
}