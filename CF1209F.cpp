#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const ll mod=1e9+7;
ll ans[N];
int n,m,tot,vis[N];
vector<int>e[N][10],q[N];
void bfs()
{
    int t=0;
    q[++t].push_back(1),vis[1]=1;
    for(int i=1;i<=t;i++)
        for(int j=0;j<=9;j++)
        {
            bool flag=0;
            for(auto u:q[i])
                for(auto v:e[u][j])
                {
                    if(vis[v]) continue;
                    vis[v]=flag=1;
                    q[t+1].push_back(v);
                    ans[v]=(10ll*ans[u]+j)%mod;
                }
            if(flag) t++;
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    tot=n;
    for(int i=1;i<=m;i++)
    {
        int u,v,w=i;
        scanf("%d%d",&u,&v);
        vector<int>a;
        while(w) a.push_back(w%10),w/=10;
        reverse(a.begin(),a.end());
        int len=a.size(),x=u,y;
        for(int i=0;i<len;i++)
        {
            y=(i==len-1)?v:++tot;
            e[x][a[i]].push_back(y);
            x=y;
        }
        for(int i=0;i<len;i++)
        {
            y=(i==len-1)?u:++tot;
            e[x][a[i]].push_back(y);
            x=y;
        }
    }
    bfs();
    for(int i=2;i<=n;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
