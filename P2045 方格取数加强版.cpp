#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,k,a[55][55];
struct edge
{
    int nxt,to,cap,flow;
}e[maxn];

int head[maxn],tot,cur[maxn],vis[maxn];

void Add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w,0};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0,0};
    head[v]=tot;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((i+j)^1)
            {
                
            }
        }
    return 0;
}