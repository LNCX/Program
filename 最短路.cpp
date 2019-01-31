#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=5e5+5;
const int inf=0x3f3f3f3f;
struct node
{
	int v;
	int w;
	int nxt;
}edg[maxm];
long long dis[maxn];
int n,m,s,k,num,used[maxn];
int head[maxm],h[maxm],q[maxm],len=1;
void add(int from,int to,int w)
{
	edg[++num].nxt=head[from];
	edg[num].v=to;
	edg[num].w=w;
	head[from]=num;
}
void pop()
{
	int f=1,s;
	h[1]=h[len],q[1]=q[len],len--;
	while(2*f<=len)
	{
		s=h[f*2]<h[f*2+1]?(f*2):(f*2+1);
		if(h[f]<=h[s]) break;
		else
		{
			swap(h[f],h[s]);
			swap(q[f],q[s]);
			f=s;
		}
	}
}
void push(int a,int b)
{
	int s=++len,f;
	h[len]=a,q[len]=b;
	while(1<=s)
	{
		f=s/2;
		if(h[f]<=h[s]) break;
		else
		{
			swap(h[f],h[s]);
			swap(q[f],q[s]);
			f=s;
		}
	}
}
int main()
{	
	int t;
	scanf("%d%d%d%d",&n,&m,&s,&t)
	/*scanf("%d%d%d",&n,&m,&s)*/;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	memset(dis,inf,sizeof(dis));
	dis[s]=0,h[1]=0,q[1]=s;
	while(len)
	{
		k=q[1];pop();
		if(!used[k])
		{
			used[k]=true;
			for(int i=head[k];i!=0;i=edg[i].nxt)
			{
				int x=edg[i].w,y=edg[i].v;
				if(!used[y]&&dis[y]>dis[k]+x)
				{
					dis[y]=dis[k]+x;
					push(dis[y],y);
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++)
		if(dis[i]==inf) printf("2147483647 ");
		else printf("%d ",dis[i]);*/
	cout<<dis[t]<<endl;
}
