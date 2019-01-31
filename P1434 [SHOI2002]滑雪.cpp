#include<iostream>
using namespace std;
int a[105][105],f[105][105];
int n,m,ans;
int dx[4]={0,-1,0,1},
	dy[4]={1,0,-1,0};
 int dfs(int x,int y)
{
    if (f[x][y]) return f[x][y];
    int t=1;
    for(int i=0;i<=3;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=1 && nx<=n && ny>=1 && ny<=m && a[x][y]<a[nx][ny])
            t=max(dfs(nx,ny)+1,t);
    }
    f[x][y]=t;
    return t;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		ans=max(ans,dfs(i,j));
	cout<<ans<<endl;
	return 0;
 }
