#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+7,mod=1e9+7;
int n,m,B,p[N];
ll ans,s[2][250][N],v[N];
void add(int t,int id,int x,ll v)
{
    if(!x)return;
    while(x<=n)s[t][id][x]=(s[t][id][x]+v+mod)%mod,x+=x&-x;
}
ll ask(int t,int id,int x)
{
    if(x<0)return 0;
    ll ret=0;while(x)ret=(ret+s[t][id][x])%mod,x-=x&-x;
    return ret;
}
void calc(int a,int b,int c)
{
    if(p[a]<p[c])ans=(ans+v[a]+v[c])%mod;else ans=(ans-v[a]-v[c]+2*mod)%mod;
    if(p[b]<p[c])ans=(ans-v[b]-v[c]+2*mod)%mod;else ans=(ans+v[b]+v[c])%mod;
}
int main()
{
    scanf("%d%d",&n,&m),B=sqrt(n*17);
    for(int i=0;i<n;i++)scanf("%d%lld",&p[i],&v[i]),add(0,i/B,p[i],v[i]),add(1,i/B,p[i],1);
    for(int i=n-1;~i;i--)
    {
        ans=(ans+ask(0,n/B+1,p[i])+ask(1,n/B+1,p[i])*v[i])%mod;
        add(0,n/B+1,p[i],v[i]),add(1,n/B+1,p[i],1);
    }
    while(m--)
    {
        int x,y,idx,idy;
        scanf("%d%d",&x,&y),x--,y--;
        if(x==y){printf("%lld\n",ans);continue;}
        if(x>y)swap(x,y);
        idx=x/B,idy=y/B;
        if(p[x]<p[y])ans=(ans+v[x]+v[y])%mod;else ans=(ans-v[x]-v[y]+2*mod)%mod;
        if(idx==idy)
        {
            for(int j=x+1;j<y;j++)calc(x,y,j);
            swap(p[x],p[y]),swap(v[x],v[y]);
            printf("%lld\n",ans);
            continue;
        }
        for(int j=x+1;j<idx*B+B;j++)calc(x,y,j);
        for(int j=idy*B;j<y;j++)calc(x,y,j);
        for(int j=idx+1;j<idy;j++)
        {
            ans=(ans-2*ask(0,j,p[x])+ask(0,j,n)-(2*ask(1,j,p[x])-B+mod)*v[x]%mod+mod)%mod;
            ans=(ans+2*ask(0,j,p[y])-ask(0,j,n)+(2*ask(1,j,p[y])-B+mod)*v[y]%mod+mod)%mod;
        }
        add(0,idx,p[x],-v[x]),add(0,idy,p[y],-v[y]),add(1,idx,p[x],-1),add(1,idy,p[y],-1);
        swap(p[x],p[y]),swap(v[x],v[y]);
        add(0,idx,p[x],v[x]),add(0,idy,p[y],v[y]),add(1,idx,p[x],1),add(1,idy,p[y],1);
        printf("%lld\n",ans);
    }
}