#pragma optimize GCC("O2")
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=3e5+5;
inline int read()
{
    char c=getchar();
    int x=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
int n,m;
struct edge
{
    int nxt,to;
}e[maxm<<1]; 
bool used[maxn],vis[maxm<<1];
int head[maxn],tot=-1;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
    e[++tot]=(edge){head[v],u};
    head[v]=tot;
}
int dfn[maxn],st[maxn],top,dfstime,low[maxn];
inline void tarjan(int x, int from)
{
	dfn[x]=low[x]=++dfstime;
	for(int i=head[x];i!=-1;i=e[i].nxt)
    {
		int v=e[i].to;
		if(!dfn[v])
        {
			tarjan(v,i);
			low[x]=min(low[x],low[v]);
			if(low[v]>dfn[x]) {puts("0");exit(0);}
		}
        else if(i!=(from^1)) low[x]=min(low[x],dfn[v]);
	}
}
void dfs(int u)
{
    if(used[u]) return ;
    used[u]=1;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        if(vis[i]) continue;
        vis[i^1]=vis[i]=true;
        printf("%d %d\n",u,e[i].to);
        dfs(e[i].to);
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        head[i]=-1;
    for(int i=1;i<=m;i++)
        add(read(),read());
    tarjan(e[0].to,-1);
    puts("");
    dfs(e[0].to);
    return 0;   
}