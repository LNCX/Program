#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
vector<int>g[maxn];
int n,m,f[maxn],mi[maxn],w[maxn];
void dfs(int x,int minx,int fa)
{
    int flag=1; 
    minx=min(w[x],minx);
    if(mi[x]>minx) mi[x]=minx,flag=0;
    int maxx=max(f[fa],w[x]-minx);
    if(f[x]<maxx) f[x]=maxx,flag=0;
    if(flag) return;
    for(int i=0;i<g[x].size();i++) dfs(g[x][i],minx,x);
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(mi,inf,sizeof(mi));
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x].push_back(y);
        if(z==2) g[y].push_back(x);
    }
    dfs(1,inf,0);
    printf("%d\n",f[n]);
    return 0;
}