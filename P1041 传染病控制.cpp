#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n,p,head[maxn],tot;
struct Edge
{
    int nxt,to;
}e[maxn<<1];
void add(int u,int v)
{
    e[++tot]=(Edge){head[u],v};
    head[u]=tot;
}
int dfs(int u,int fa)
{
    
}
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    return 0;
}