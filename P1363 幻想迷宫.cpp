#include<bits/stdc++.h>
using namespace std;
const int maxn=1505;
int n,m,flag,
    dx[5]={1,-1,0,0},
    dy[5]={0,0,1,-1};
char s[maxn][maxn];
int vis[maxn][maxn][3],a[maxn][maxn];
void dfs(int x,int y,int px,int py)
{
    if(flag) return;
    if(vis[x][y][0]&&(vis[x][y][1]!=px||vis[x][y][2]!=py))
    {
        flag=1;
        return;
    }
    vis[x][y][1]=px,vis[x][y][2]=py,vis[x][y][0]=1;
    for(int i=0;i<4;i++)
    {
        int x0=(x+dx[i]+n)%n,y0=(y+dy[i]+m)%m;
        int px0=px+dx[i],py0=py+dy[i];
        if(!a[x0][y0])
            if(vis[x0][y0][1]!=px0||vis[x0][y0][2]!=py0||!vis[x0][y0][0])
                dfs(x0,y0,px0,py0);
    }
}
int main()
{
    int x,y;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        flag=0;
        for(int i=0;i<n;i++)
        scanf("%s",s[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='#')
                    a[i][j]=1;
                else if(s[i][j]=='S')
                    x=i,y=j;  
        dfs(x,y,x,y);
        if(flag) puts("Yes");
        else puts("No");
    }
}