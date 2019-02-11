#include<bits/stdc++.h>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int ans=inf,dis[maxn],vis[maxn];
int tot,head[maxn],to[maxn<<1],nxt[maxn<<1],num[maxn];
void add(int u,int v)
{
    nxt[++tot]=head[u];
    to[tot]=v;
    head[u]=tot;
}
void SPFA(int s)
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    q.push(s),vis[s]=1,dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i!=0;i=nxt[i])
        {
            int v=to[i];
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d%d",&num[i],&l,&r);
        if(l) add(i,l),add(l,i);
        if(r) add(i,r),add(r,i);
    }
    for(int i=1;i<=n;i++)
    {
        SPFA(i);
        int mid=0;
        for(int i=1;i<=n;i++)
            mid+=dis[i]*num[i];
        ans=min(mid,ans);
    }   
    cout<<ans<<endl;
    return 0;
}