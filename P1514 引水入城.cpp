#include<bits/stdc++.h>
using namespace std;
const int N=512,ax[4]={1,-1,0,0},ay[4]={0,0,1,-1};
struct node
{
    int l,r;
};
int n,m,cap,res=1,mxv,gr[N][N],f[N];
bool vis[N][N];
node seg[N][N];
void dfs(int x,int y)
{
    if(vis[x][y])return;
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+ax[i],ny=y+ay[i];
        if(nx>n||nx<1||ny>m||ny<1||gr[nx][ny]>=gr[x][y])continue;
        dfs(nx,ny);
        seg[x][y].l=min(seg[x][y].l,seg[nx][ny].l);
        seg[x][y].r=max(seg[x][y].r,seg[nx][ny].r);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&gr[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i!=n)seg[i][j].l=N,seg[i][j].r=0;
            else seg[i][j].l=seg[i][j].r=j;
    for(int i=1;i<=m;i++)dfs(1,i);
    for(int i=1;i<=m;i++)cap+=!vis[n][i];
    if(cap)
    {
        cout<<0<<endl<<cap<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
        for(int j=seg[1][i].l;j<=seg[1][i].r;j++)
            if(f[j]>f[seg[1][i].l-1]||!f[j])
                f[j]=f[seg[1][i].l-1]+1;
    cout<<1<<endl<<f[m]<<endl;
    return 0;
}