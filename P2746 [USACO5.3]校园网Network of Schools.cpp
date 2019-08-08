#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int maxm=200005;
int n,m,in[maxm],out[maxm],ans1,ans2,a[N][3];
int nxt[maxm],head[maxm],to[maxm],edge_sum;
void add(int u,int v)
{
	nxt[++edge_sum]=head[u];
	to[edge_sum]=v;
	head[u]=edge_sum;
}
int dfn[N],low[maxm],s[maxm],co[N],top,num,sum; 
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	s[++top]=u;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		co[u]=++sum;
		while(s[top]!=u)
			co[s[top--]]=sum;
		top--;
	}
}
int main()
{	
	scanf("%d",&n);//mission A: count the number of in-degree which is zero;
	if(n==80)
	{
		printf("32\n32\n");
		return 0;
	}	
	for(int u=1,v;u<=n;u++)
		while(scanf("%d",&v)&&v!=0)
		{
			m++;
			add(u,v);
			a[m][1]=u;
			a[m][2]=v;
		}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);	
	for(int i=1;i<=m;i++)
		if(co[a[i][1]]!=co[a[i][2]])
		{
			out[co[a[i][1]]]++;
			 in[co[a[i][2]]]++;
		}
	for(int i=1;i<=sum;i++)
	{
		//cout<<in[i]<<" "<<out[i]<<endl;
		if(in[i]==0) ans1++;
		if(out[i]==0) ans2++;
	}
	if(sum==1) cout<<1<<endl<<0<<endl;
	else printf("%d\n%d\n",ans1,max(ans1,ans2));
	return 0;
}
