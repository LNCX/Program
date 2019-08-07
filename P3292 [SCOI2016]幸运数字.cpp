#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5,M=60;
vector<int>e[N];
int dep[N],f[N][20];
ll w[N],p[N][20][M+5],s[M+5];
void insert(ll x,ll *p)
{
    for(int i=60;i>=0;i--)
    {
        if(!(x>>i)) continue;
        if(!p[i]){p[i]=x;break;}
        else x^=p[i];
    }
}
void merge(ll *a,ll *b,ll *c)
{
    for(int i=0;i<=M;i++) c[i]=a[i];
    for(int i=0;i<=M;i++) insert(b[i],c);
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    insert(w[u],p[u][0]),insert(w[fa],p[u][0]);
    for(int i=1;(1<<i)<=dep[u];i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
        merge(p[u][i-1],p[f[u][i-1]][i-1],p[u][i]);
    }
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void merge(ll *a,ll *b)
{
    for(int i=0;i<=M;i++)
        insert(a[i],b);
}
int jump(int x,int k)
{
    merge(p[x][k],s);
    return f[x][k];
}
void lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=15;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=jump(x,i);
    if(x==y) return;
    for(int i=15;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=jump(x,i),y=jump(y,i);
    jump(x,0);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        memset(s,0,sizeof(s));
        lca(u,v);
        ll res=0;
        for(int i=M;i>=0;i--)
            if((res^s[i])>res)            
                res^=s[i];
        printf("%lld\n",res);
    }
    return 0;
}