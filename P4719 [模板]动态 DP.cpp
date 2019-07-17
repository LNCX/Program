#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to;
}e[N<<1];
struct mat
{
    int c[3][3];
    friend mat operator*(const mat a,const mat b)
    {
        mat res;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                res.c[i][j]=-inf;
        for(int k=1;k<=2;k++)
            for(int i=1;i<=2;i++)
                for(int j=1;j<=2;j++)
                    res.c[i][j]=max(a.c[i][k]+b.c[k][j],res.c[i][j]);
        return res;                  
    }
};
int head[N],tot,w[N],top[N],seg[N],top[N],rev[N],size[N],f[N],dep[N],son[N];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void dfs(int u,int fa)
{
    f[u]=fa; 
    size[u]=1;
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        size[u]+=size[u];
        if(size[son[u]]<size[v]) son[u]=v;
    }
}
void dfs(int u)
{
    if(son[u])
    {
        top
        dfs(son[u]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,0);
    seg[0]=seg[1]=rev[1]=top[1]=1;
    dfs(1);
    return 0;
}