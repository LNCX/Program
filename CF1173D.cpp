#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=998244353;
typedef long long ll;
struct edge
{
    int nxt,to;
}e[N<<1];
int head[N],tot;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
ll dp(int u,int fa)
{
    ll res=1,cnt=0;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        cnt++;
        (res*=dp(v,u))%=mod;
    }
    for(ll i=1;i<=cnt;i++)
        (res*=i)%=mod;
    if(fa) (res*=(cnt+1))%=mod;
    return res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    printf("%lld\n",(n*dp(1,0))%mod);
    return 0;
}