#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL n,m;
struct Edge
{
    int to,w,nxt;
}e[maxn<<1];
int head[maxn],tot=1;
void add(int u,int v,int w)
{
    e[++tot]=(Edge){v,w,head[u]}
    head[u]=tot;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        LL u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}