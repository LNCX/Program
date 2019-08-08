#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
struct edge
{
    int nxt,to;
}e[N<<1];
int n;
int a[N],cnt[N],dep[N];
int head[N],tot,f[N][20];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
    e[++tot]=(edge){head[v],u};
    head[v]=tot;
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=19;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
}
void dfs1(int u,int fa)
{
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs1(v,u);
        cnt[u]+=cnt[v];
    }
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) 
			x=f[x][i];
		if(x==y) return x;
	}
	for(int i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    dfs(1,0);
    for(int i=1;i<n;i++)
    {  
        int x=lca(a[i],a[i+1]);
        cnt[a[i]]++,cnt[a[i+1]]++;
        cnt[x]--,cnt[f[x][0]]--;
    }
    dfs1(1,0);
    for(int i=2;i<=n;i++)
        cnt[a[i]]--;
    for(int i=1;i<=n;i++)
        printf("%d\n",cnt[i]);
    return 0;
}