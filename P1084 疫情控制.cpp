#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e4+5;
struct Edge
{
    int v,w,nxt;
}e[maxn<<1];
struct node
{
    int r;
    LL w;
    bool operator<(const node &x) const 
    {
        return w<x.w;
    }
}a[maxn];
LL dis[maxn],ans;
int n,m,f[maxn],trp[maxn],vis[maxn];
int head[maxn],tot,dep[maxn],flag,b[maxn];
void add(int u,int v,int w)
{
    e[++tot].nxt=head[u];
    e[tot].v=v;
    e[tot].w=w;
    head[u]=tot;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    if(fa==1) f[u]=u,flag++;
    else f[u]=f[fa];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dis[v]=(LL)(dis[u]+e[i].w);
        dfs(v,u);
    }
}
bool check(LL t)
{
    int cnt=0,cnt1=0,cnt2=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++)
    {
        int x=trp[i];
        int len1=dis[x],len2=dis[x]-dis[f[x]];
        if(len1<=t)
        {
            a[++cnt1].r=f[x];
            a[cnt1].w=t-len1;
            cnt++;
        }
        if(len2<=t)
            vis[f[x]]=1,cnt++;
    }
    if(cnt<flag) return false;
    sort(a+1,a+1+cnt1);
    for(int i=1;i<=n;i++)
        if(a[i].w-dis[a[i].r]<0&&!vis[a[i].r])
            a[i].w=-1,vis[a[i].r]=1;
    for(int i=head[1];i!=0;i=e[i].nxt)
    {
        int v=e[i].v;
        if(!vis[v])
            b[++cnt2]=e[i].w;
    }
    sort(b+1,b+1+cnt2);
    while(cnt2>0&&cnt1>0)
    {
        while(a[cnt1].w==-1)
            cnt1--;
        if(a[cnt1].w>=b[cnt2])
        {
            cnt1--;cnt2--;
            continue;
        }
        else return false;
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
        scanf("%d",&trp[i]);
    dfs(1,0);
    if(flag>m)
    {              
        puts("-1");
        return 0;
    }
    LL l=1,r=15;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1; 
    }
    cout<<ans<<endl;
    return 0;
}