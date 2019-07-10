#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
int ex0,ey0,sx0,sy0,tx0,ty0,n,m;
int g[maxn][maxn];
bool vis[maxn][maxn][maxn][maxn];
int dx[]={0,1,0,-1},
    dy[]={1,0,-1,0};
struct node{int ex,ey,sx,sy,cnt;};
queue<node>q;
int bfs()
{
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    q.push((node){ex0,ey0,sx0,sy0,0});
    vis[ex0][ey0][sx0][sy0]=1;
    while(!q.empty())
    {
        node h=q.front();q.pop();
        if(h.sx==tx0&&h.sy==ty0)
            return h.cnt;
        for(int i=0;i<4;i++)
        {
            int l=h.ex+dx[i],r=h.ey+dy[i];
            if(l==h.sx&&r==h.sy)
            {
                if(!vis[l][r][h.ex][h.ey])
                {
                    vis[l][r][h.ex][h.ey]=1;
                    q.push((node){l,r,h.ex,h.ey,h.cnt+1});
                }
            }
            else if(!vis[l][r][h.sx][h.sy]&&l>0&&l<=n&&r>0&&r<=m&&g[l][r]==1)
            {
                vis[l][r][h.sx][h.sy]=1;
                q.push((node){l,r,h.sx,h.sy,h.cnt+1});
            }
        }
    }
    return -1;
}
int main()
{
    int q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
    while(q--)
    {
        scanf("%d%d %d%d %d%d",&ex0,&ey0,&sx0,&sy0,&tx0,&ty0);
        cout<<bfs()<<endl;
    }
    return 0;
}