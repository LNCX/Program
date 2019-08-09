#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
bitset<N>vis;
int d[N],to[N],f[N],s[N][2],ans;
bool dfs(int u)
{
    for(int i=0;i<2;i++)
    {
        int v=s[u][i];
        if(vis[v]) continue;
        vis[v]=true;
        if(f[v]==-1||dfs(f[v]))
        {
            to[u]=v,f[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    for(int i=0;i<n;i++)
    {
        s[i][0]=(i+d[i]+n)%n,s[i][1]=(i-d[i]+n)%n;
        if(s[i][0]>s[i][1]) swap(s[i][0],s[i][1]);
        f[i]=to[i]=-1;
    }
    for(int i=n-1;i>=0;i--)
    {
        vis.reset();
        if(!dfs(i))
        {
            puts("No Answer");
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",to[i]);
    return 0;
}