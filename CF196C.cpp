#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1505,inf=0x3f3f3f3f;
struct point
{
    LL x,y,id,num;
}p[maxn],s;
bool operator< (point a,point b)
{
    return (a.x-s.x)*(b.y-s.y)>(a.y-s.y)*(b.x-s.x);
}  
struct Edge
{
    LL v,nxt;
}e[maxn<<1];
LL head[maxn],tot;
LL n,size[maxn],ans[maxn];
void add(LL from,LL to)
{
    e[++tot].nxt=head[from];
    e[tot].v=to;
    head[from]=tot;
}
void dfs(int u,int fa)
{
    size[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
}
void solve(LL u,LL fa,LL l,LL r)
{
    LL x=l;
    for(LL i=l+1;i<=r;i++)
        if(p[i].y<p[x].y||p[i].y==p[x].y&&p[i].x<p[x].x)
            x=i;
    if(x!=l) swap(p[x],p[l]);    
    s=p[l],ans[p[l].id]=u;
    sort(p+l+1,p+r+1);
    LL last=l+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        solve(v,u,last,last+size[v]-1);
        last+=size[v];
    }
}
int main()
{
    cin>>n;
    for(LL i=1;i<n;i++)
    {
        LL u,v;
        scanf("%lld%lld",&u,&v);
        add(u,v),add(v,u);
    }
    for(LL i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y),p[i].id=i;
    dfs(1,0);
    solve(1,0,1,n);
    for(int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    puts("");
}