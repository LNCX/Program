#include<bits/stdc++.h>
using namespace std;
const int N=1008;
int dx[]={0,1,0,-1},
    dy[]={1,0,-1,0};
int n,m,p[N][N];
bool vis[N][N];
bool dfs(int x,int y,int mid)
{
    if(x==n) return true;
    vis[x][y]=1;
    for(int i=0;i<4;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a<1||a>n||b<1||b>m||vis[a][b]||p[a][b]>mid)
            continue;
        if(dfs(a,b,mid)) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&p[i][j]);
    int l=0,r=N;
    while(l<=r)
    {
        memset(vis,0,sizeof vis);
        int mid=(l+r)>>1;
        if(dfs(1,1,mid)==true)
            r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
}