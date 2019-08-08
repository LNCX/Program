#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,inf=0x7fffffff;
struct edge
{
    int nxt,to,w;
}e[N<<1];
int head[N],tot,cnt[3],dis[N],now[3];
int n,size[N],s,mx[N],vis[N],rt,ans;
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,w};
    head[v]=tot;
}
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
    now[dis[u]]++;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||vis[v]) continue;
        dis[v]=(dis[u]+e[i].w)%3;
        getdis(v,u);
    }
}
void calc(int u)
{
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]) continue;
        memset(now,0,sizeof(now));
        dis[v]=e[i].w%3;
        getdis(v,u);
        ans+=2*(now[0]+now[0]*cnt[0]+now[1]*cnt[2]+now[2]*cnt[1]);
        for(int i=0;i<3;i++)
            cnt[i]+=now[i];
    }
    memset(cnt,0,sizeof(cnt));
}
void divide(int u)
{
    vis[u]=1;
    calc(u);
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]) continue;
        s=size[v],mx[rt=0]=inf;
        find(v,0),divide(rt);   
    }
}
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void print(int a,int b)
{
    int x=gcd(a,b);
    a/=x,b/=x;
    printf("%d/%d",a,b);
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    mx[rt]=s=n;
    find(1,0);
    divide(rt);
    print(ans+n,n*n);
    return 0;
}