#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
struct Edge
{
    int v,w,nxt;
}e[maxn<<1];
int n,m,head[maxn],tot,trp[maxn];
void add(int u,int v,int w)
{
    e[++tot].nxt=head[u];
    e[tot].v=v;
    e[tot].w=w;
    head[u]=tot;
}
int f[maxn][20];
void dfs(int u,int fa,int s)
{

}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
        scanf("%d",trp[i]);
    dfs(1,1,0);
    
    return 0;
}