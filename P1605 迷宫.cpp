#include<bits/stdc++.h>
using namespace std;
int ans,a[6][6],used[6][6];
int n,m,t,sx,sy,fx,fy;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y)
{
    if(x==fx&&y==fy)
    {
        ans++;
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&!a[nx][ny]&&!used[nx][ny])
        {
            used[nx][ny]=1;
            dfs(nx,ny);
            used[nx][ny]=0;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i=1;i<=t;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=1;
    }
    used[sx][sy]=1;
    dfs(sx,sy);
    cout<<ans<<endl;
}