#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e7+5,inf=0x3f3f3f3f;
inline int read()
{
    int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();   
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
struct edge
{
    int nxt,to,w;
}e[maxn<<1];
int len[maxm],ans[maxm];
int n,m,que[maxn],s,vis[maxn];
int head[maxn],tot,dis[maxn],q[maxn],r[maxn];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,w};
    head[v]=tot;
}
int size[maxn],mx[maxn],rt;
void find(int u,int fa)
{
    size[u]=1,mx[u]=0;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||vis[v]) continue;
        find(v,u);
        size[u]+=size[v];
        mx[u]=max(mx[u],size[v]);
    }
    mx[u]=max(mx[u],s-size[u]);
    if(mx[u]<mx[rt]) rt=u;
}
void getdis(int u,int fa)
{
    r[++r[0]]=dis[u];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||vis[v]) continue;
        dis[v]=dis[u]+e[i].w;
        getdis(v,u);
    }
}
void calc(int u)
{
    q[0]=0;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[u]) continue;
        r[0]=0,dis[v]=e[i].w;
        getdis(v,u);
        for(int j=r[0];j>0;j--)
            for(int k=1;k<=m;k++)
                if(que[k]>=r[j])
                    ans[k]|=len[que[k]-r[j]];
        for(int j=r[0];j>0;j--)
            q[++q[0]]=r[j],len[r[j]]=1;
    }
    for(int i=1;i<=q[0];i++)
        len[q[i]]=0;
}
void divide(int u)
{
    vis[u]=len[0]=1;
    calc(u);
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]) continue;
        s=size[v],mx[rt=0]=inf;
        find(v,0),divide(rt);
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }
    for(int i=1;i<=m;i++)
        que[i]=read();
    mx[rt]=s=n;
    find(1,0);
    divide(rt);
    for(int i=1;i<=m;i++)
        printf("%s\n",(ans[i])?"AYE":"NAY");
    return 0;
}