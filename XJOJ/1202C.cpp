#include<bits/stdc++.h>
using namespace std;
const int maxn=505,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,w;
}e[maxn<<1];
int n,d,ans=1;
int head[maxn],tot=1,del[maxn],dis[maxn],maxx[maxn];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w},head[u]=tot;
    e[++tot]=(edge){head[v],u,w},head[v]=tot;
}
priority_queue< pair<int,int> >q,em;
int get_dis(int u,int fa)
{
    maxx[u]=0;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||del[v]) continue;
        maxx[u]=max(get_dis(v,u)+e[i].w,maxx[u]);
    }
    return maxx[u];
}
void dfs(int u,int fa)
{
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    memset(dis,-inf,sizeof(dis)),q=em;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||del[v]) continue;
        dis[u]=0;
        dis[v]=get_dis(v,u)+e[i].w;
    }
    for(int i=1;i<=n;i++)
        if(dis[i]>=0)
            q.push(make_pair(dis[i],i));
    while(!q.empty())
    {
        int x=q.top().first;
        int y=q.top().second;
        q.pop();
        if(x>d||x+q.top().first>d)
        {
            ans++;
            del[y]=1;
        }
        else break;
    }
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
