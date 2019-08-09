#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e5+5;
const LL mod=998244353;
int n,m;
LL ans,sum[2],a[N<<1];
int head[N<<1],edge_sum;
bool vis[N],flag=0;
struct node
{
    int to,nxt;
}edge[N<<1];
void clear()
{
    ans=1;
    flag=edge_sum=0;
    for(int i=1;i<=n;i++)
        vis[i]=0,head[i]=0;
}
void add(int u,int v)
{
    edge[++edge_sum].nxt=head[u];
    edge[edge_sum].to=v;
    head[u]=edge_sum;
}
LL power(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void dfs(int x,int d)
{
    if(flag) return;
    vis[x]=1;sum[d]++;a[x]=d;
    for(int i=head[x];i!=0;i=edge[i].nxt)
    {
        int y=edge[i].to;
        if(vis[y])
        {
            if(a[y]==1-d) continue;
            else
            {
                flag=1;
                return;
            }
        }
        else 
            dfs(y,1-d);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v),add(v,u);
        }
        for(int u=1;u<=n;u++)
        {
            sum[0]=sum[1]=0;
            if(!vis[u])
                dfs(u,0);
            if(flag) break;
            if(sum[0]==sum[1]&&sum[0]==0) continue;
            ans=ans*(power(2,sum[0])+power(2,sum[1]))%mod;
        }
        if(flag) printf("0\n");
        else printf("%lld\n",ans);
    }
}