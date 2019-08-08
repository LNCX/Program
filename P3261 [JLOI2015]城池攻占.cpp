#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
vector<int>e[N];
int n,m,ans1[N],ans2[N];
int rt[N],ch[N][2],dis[N];
ll h[N],a[N],v[N],s[N],c[N];
ll tag[N][2],val[N];
void pushdown(int x)
{
    for(int i=0;i<2;i++)
        if(ch[x][i])
        {
            tag[ch[x][i]][0]+=tag[x][0];
            tag[ch[x][i]][1]*=tag[x][1];
            val[ch[x][i]]*=tag[x][1];
            val[ch[x][i]]+=tag[x][0];
        }   
}
void sign(int x,ll y,int t)
{
    if(t==0)
    {
        tag[x][t]+=y;
        val[x]+=y;
    }
    if(t==1)
    {
        tag[x][t]*=y;
        tag[x][t^1]*=y;
        val[x]*=y;
    }
}
int merge(int x,int y)
{
    pushdown(x),pushdown(y);
    if(!x||!y) return x|y;
    if(val[x]>val[y]) swap(x,y);
    ch[x][1]=merge(ch[x][1],y);
    if(dis[ch[x][1]]>dis[ch[x][0]])
        swap(ch[x][1],ch[x][0]);
    dis[x]=dis[ch[x][1]]+1;
    return x;
}
int pop(int x){return merge(ch[x][0],ch[x][1]);}
void dfs(int u,int fa)
{
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        rt[u]=merge(rt[u],rt[v]);
    }
    while(val[pop(rt[u])])
    sign(rt[u],)
    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    for(int i=2;i<=n;i++)
    {
        int f;
        scanf("%lld%lld%lld",&f,&a[i],&v[i]);
        e[f].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld",&s[i],&c[i]);
        val[i]=s[i],tag[i][1]=1;
        rt[c[i]]=merge(i,c[i]);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans1[i]);
    for(int i=1;i<=m;i++) printf("%d\n",ans2[i]);
    return 0;
}