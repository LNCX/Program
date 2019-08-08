#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
struct edge
{
    int nxt,to,w;
}e[N<<1];
int n,s,ans;
int head[N],tot;
ll f[N],t[N];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,u);
        t[u]=max(t[u],(ll)e[i].w+t[v]);
        f[u]+=f[v];
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)continue;
        f[u]+=t[u]-((ll)t[v]+e[i].w);
    }
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dfs(s,0);
    cout<<f[s]<<endl;
    return 0;
}