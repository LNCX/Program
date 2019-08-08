#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m;
vector<int>e[N];
ll h[N],a[N],v[N],s[N],c[N];
struct leftlist
{
    ll tag[N][2],val[N];
    int rt[N],ch[N][2],dis[N];
    leftlist(){for(int i=1;i<=N-5;i++)tag[i][1]=1;}
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
}T;
void dfs(int u,int fa)
{

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
        scanf("%lld%lld",&s[i],&c[i]);
    dfs(1,0);
    return 0;
}