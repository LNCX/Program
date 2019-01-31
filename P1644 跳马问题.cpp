#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int dx[4]={2,1,-1,-2},dy[4]={1,2,2,1};
void dfs(int x,int y)
{
    if(x==n&&y==m) ans++;
    if(x<0||x>n||y>m||y<0) return ;
    for(int i=0;i<4;i++) 
        dfs(x+dx[i],y+dy[i]);
}
int main()
{
    cin>>n>>m;
    dfs(0,0);
    cout<<ans<<endl;
}