#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5,inf=0x3f3f3f3f;
int n,m,b,l=inf,r=-inf,res;
int head[N],tot,f[N],dis[N],vis[N];
struct edge
{
	int nxt,to,w;
}e[M];
void add(int u,int v,int w)
{
	e[++tot]=(edge){head[u],v,w},head[u]=tot;
	e[++tot]=(edge){head[v],u,w},head[v]=tot;
}
bool spfa(int x)
{
	memset(dis,inf,sizeof(dis));
	queue<int>q;
	q.push(1),vis[1]=1,dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=0;;
		for(int i=head[u];i!=0;i=e[i].nxt)
		{
			int v=e[i].to,w=e[i].w;
			if(dis[u]+w<dis[v]&&f[v]<=x)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return dis[n]<=b;
}
int main()
{
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		l=min(f[i],l);
		r=max(f[i],r);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(spfa(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	spfa(res)?printf("%d\n",res):puts("AFK");
	return 0;
}