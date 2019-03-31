#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
const int maxn=1e5+5;
struct edge
{
    int nxt,to;
}e[maxn<<1];
int n,m,rt,mod,w[maxn],head[maxn],tot;
int size[maxn],f[maxn],dep[maxn];
void edge_add(int u,int v)
{
    e[++tot]=(edge){head[u],v};head[u]=tot;
    e[++tot]=(edge){head[v],u};head[v]=tot;
}
void dfs1(int u,int fa)
{
    f[u]=fa;
    size[u]=1;
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs1(v,u);
        size[u]+=size[v];
    }
}

int main()
{
    n=read(),m=read(),rt=read(),mod=read();
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
        edge_add(read(),read());
    dfs1(rt,0);
    
    return 0;
}