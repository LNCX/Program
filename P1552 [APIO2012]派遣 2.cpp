#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
vector<int>e[N];
long long ans;
int c[N],w[N],rt[N],n,m;
int ch[N][2],val[N],dis[N],size[N],sum[N];
class leftlist
{
    public:
    int merge(int x,int y)
    {
        if(!x||!y) return x|y;
        if(val[x]<val[y]) swap(x,y);
        ch[x][1]=merge(ch[x][1],y);
        if(dis[ch[x][0]]<dis[ch[x][1]]) 
            swap(ch[x][0],ch[x][1]);
        dis[x]=dis[ch[x][1]]+1;
        size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
        sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+val[x];
        return x;
    }
    int pop(int x){return merge(ch[x][0],ch[x][1]);}
}T;
void dfs(int u)
{
    rt[u]=u;
    size[u]=1;
    val[u]=sum[u]=c[u];
    ch[u][0]=ch[u][1]=dis[u]=0;
    for(auto v:e[u])
    {
        dfs(v);
        rt[u]=T.merge(rt[u],rt[v]);
    }
    while(sum[rt[u]]>m&&size[rt[u]]!=0)
        rt[u]=T.pop(rt[u]);
    ans=max(ans,(long long)size[rt[u]]*w[u]);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int b;
        scanf("%lld%lld%lld",&b,&c[i],&w[i]);
        e[b].push_back(i);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}