#include<bits/stdc++.h>
using namespace std;
const int N=205;
bitset<N>vis;
int n,ans,a[N][N],f[N];
bool dfs(int u)
{
    for(int v=1;v<=n;v++)  if(a[u][v]&&!vis[v])
    {
        vis[v]=1;
        if(!f[v]||dfs(f[v]))
        {
            f[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
        {
            vis.reset();
            ans+=dfs(i);
        }
        if(ans<n) puts("No");
        else puts("Yes");
    }
    return 0;
}