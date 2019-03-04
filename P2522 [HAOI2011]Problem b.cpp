#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=50000;
int k,cnt,prim[N+50],mu[N+50],vis[N+50],sum[N+50];
void init()
{
    vis[1]=mu[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!vis[i])
        {
            prim[++cnt]=i;
            mu[i]=-1;
        } 
        for(int j=1;j<=cnt&&i*prim[j]<=N;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)
            {
                mu[i*prim[j]]=0;
                break;
            }
            mu[i*prim[j]]=mu[i]*-1;
        }
    } 
    for(int i=1;i<=N;i++)
        sum[i]=sum[i-1]+mu[i];
}
LL ask(int n,int m)
{
    if(n>m) swap(n,m);
    LL ans=0;
    for(int l=1,r;l<=n/k;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans+=1ll*(n/(l*k))*(m/(l*k))*(sum[r]-sum[l-1]);
    }
    return ans;
}
int main()
{
    init();
    int t; 
    scanf("%d", &t);
    while(t--)
    {
        int a,b,c,d;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        printf("%lld\n",ask(a-1,c-1)-ask(b,c-1)-ask(d,a-1)+ask(b,d));
    }
    return 0;
}