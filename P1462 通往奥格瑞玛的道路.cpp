#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e5+5;
const int inf=0x3f3f3f3f;
int n,m,b,l=inf,r,f[maxn];
int w[maxm],nxt[maxm],head[maxm],to[maxm],edge_sum;
void add(int u,int v,int c)
{
	nxt[++edge_sum]=head[u];
	to[edge_sum]=v;
	w[edge_sum]=c;
	head[u]=edge_sum;
}
int dis[maxn],used[maxn];
priority_queue<pair<int,int> >q;
int dijkstra(int s)
{
	memset(dis,inf,sizeof(dis));
	memset(used,false,sizeof(used));
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		int x=q.top().second;q.pop();
		for(int i=head[x];i!=0;i=nxt[i])
		{
			int y=to[i],z=w[i];
			if(dis[y]>dis[x]+z)
			{
				dis[y]=dis[x]+z;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
	return dis[s];
}
int main()
{
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		l=min(l,f[i]);
		r=max(r,f[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,z,x);
	}
	while(l<r)
	{
		int mid=(l+r)/2;
		if(dijkstra(mid)>=b) l=mid+1;
		else r=mid;
	}
	if(dijkstra(1)>=b)
		printf("AFK\n");
	else printf("%d\n",l);
	return 0;
}
