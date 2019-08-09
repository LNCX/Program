#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,oo=0x7fffffff;
int n,m,dep[N],f[N][20];
int head[N],tot,ansp,ansc;
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
struct edge
{
    int nxt,to;
}e[N<<1];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
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
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)  return x;
    for(int i=19;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
inline void solve(int a,int b,int c)
{
    int fa=LCA(a,b);
    ansp=fa;
    //cerr<<fa<<endl;
    ansc=dep[a]+dep[b]-(dep[fa]<<1);
    //cerr<<ansc<<endl;
    a=fa,b=c;
    fa=LCA(a,b);
    //cerr<<fa<<endl;
    ansc+=dep[a]+dep[b]-(dep[fa]<<1);
    //cerr<<ansc<<endl;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        int p=0,C=oo;
        int a=read(),b=read(),c=read();
        solve(a,b,c);if(ansc<C){C=ansc;p=ansp;}
        solve(a,c,b);if(ansc<C){C=ansc;p=ansp;}
        solve(b,c,a);if(ansc<C){C=ansc;p=ansp;}
        printf("%d %d\n",p,C);
    }
    return 0;
}