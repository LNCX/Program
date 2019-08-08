#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
int head[N],tot,keep[N],f[N][25];
struct Edge
{
    int to,nxt;
}e[N<<1];
void add(int u,int v)
{
    e[++tot].nxt=head[u];
    e[tot].to=v;
    head[u]=tot;
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    for(int i=0;i<=19;i++)
        f[u][i+1]=f[f[u][i]][i];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
}
int dis(int u)
{
    int d=0;
    for(int i=20;i>=0;i--)
        if(f[u][i]!=0&&keep[f[u][i]]==0)
            d+=(1<<i),u=f[u][i];
    d+=1;
    return d;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(n,n);keep[n]=1;
    int remain=n-k-1;
    for(int i=n-1;i>=1;i--)
    {
        if(!remain) break;
        if(keep[i]) continue;
        int d=dis(i);
        if(d<=remain)
        {
            int u=i;
            remain-=d;
            while(!keep[u])
            {
                keep[u]=1;
                u=f[u][0];
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(!keep[i])
            printf("%d ",i);
    return 0;
}