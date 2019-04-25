#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 6;
int n, m, t, f[maxn], ans;
vector<int>e[maxn];
bitset<maxn>v;
bool dfs(int x)
{
    for(int i=0;i<e[x].size();i++)
    {
        int y=e[x][i];
        if(v[y]) continue;
        v[y]=1;
        if(!f[y]||dfs(f[y]))
        {
            f[y]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    while(t--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>n||y>m) continue;
        e[x].push_back(y+n);
        e[y+n].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        v.reset();
        ans+=dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}