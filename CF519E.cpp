#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int nxt,to;
}e[N<<1];
int n,m,head[N],tot,f[N][20],dep[N],size[N];
void add(int u,int v)
{
    e[++tot]=(node){head[u],v};
    head[u]=tot;
}
void dfs(int u,int fa)
{
    size[u]=1;
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=18;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
}
int LCA(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) 
			x=f[x][i];
		if(x==y) return x;
	}
	for(int i=18;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
int fly(int x,int dis)
{
    for(int i=18;i>=0;i--)
        if((dis>>i)&1)
            x=f[x][i];
    return x;
}
int solve(int x,int y,int dis,int fa)
{
    if(dep[x]-dep[fa]<dep[y]-dep[fa])
        swap(x,y);
    int now=fly(x,dis>>1),a=fly(x,(dis>>1)-1),b=fly(y,(dis>>1)-1);
    if(now==fa)
        return size[1]-size[a]-size[b];
    else return size[now]-size[a];
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int fa=LCA(x,y),dis=dep[x]+dep[y]-(dep[fa]<<1);
        if(dis&1)
        {
            puts("0");
            continue;
        }
        if(x==y) printf("%d\n",size[1]);
        else printf("%d\n",solve(x,y,dis,fa));
    }
    return 0;
}