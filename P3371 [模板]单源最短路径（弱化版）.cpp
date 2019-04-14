#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
const int maxn=1e4+5;
const int inf=0x3f3f3f3f;
int num,n,m,s,t,head[maxm],len=1;
int h[maxn],q[maxn],dis[maxn],used[maxn];
struct node
{
	int nxt;
	int to;
	int w;
}g[maxm];
void add(int from,int to,int w)
{
	g[++num].nxt=head[from];
	g[num].to=to;
	g[num].w=w;
	head[from]=num;
}
int get()
{
	int x=q[1],i=1,t;
	h[1]=h[len--];
	while(i*2<=n)
	{
		if(h[i]>h[i*2])
			t=i*2;
		else t=i;
		if(i*2+1<=n)
			if(h[t]>h[i*2+1])
				t=i*2+1;
		if(t!=i)
		{
			swap(h[t],h[i]);
			i=t;
		}
		else break;
	}
	return x;
}
void push(int d,int x)
{
	h[++len]=d,q[len]=x;
	int i=len;
	while(i>1)
	{
		if(h[i]<h[i/2])
		{
			swap(h[i],h[i/2]);
			swap(q[i],q[i/2]);
		}
		else break;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	memset(dis,inf,sizeof(dis));
	memset(h,inf,sizeof(h));
	dis[s]=0,h[1]=dis[s],q[1]=s;
	for(int i=1;i<=n;i++)
	{
		int k=get();
		used[k]=true;
		for(int j=head[k];j!=0;j=g[j].nxt)
			if(!used[g[j].to]&&dis[g[j].to]>dis[k]+g[j].w)
			{
				dis[g[j].to]=dis[k]+g[j].w;
				push(dis[g[j].to],g[j].to);
			}
	}
	cout<<dis[t]<<endl;
	/*for(int i=1;i<=n;i++)
		if(dis[i]==inf) printf("2147483647 ");
		else printf("%d ",dis[i]);
	printf("\n");*/
}
