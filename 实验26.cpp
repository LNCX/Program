#include<bits/stdc++.h>
#define il inline
#define ll long long
#define mem(p) memset(&p,0,sizeof(p))
using namespace std;
const ll mod=1e8;
ll n,m;
struct mat{ll a[3][3],r,c;};
il mat mul(mat x,mat y)
{
    mat p;
    mem(p);
    for(int i=0;i<x.r;i++)
        for(int j=0;j<y.c;j++)
            for(int k=0;k<x.c;k++)
    p.a[i][j]=(p.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
    p.r=x.r,p.c=y.c;
    return p;
}
il void fast(ll k)
{
    mat p,ans;
    mem(p),mem(ans);
    p.r=p.c=2;
    p.a[0][0]=p.a[0][1]=p.a[1][0]=1;
    ans.r=1,ans.c=2;
    ans.a[0][0]=ans.a[0][1]=1;
    while(k)
    {
        if(k&1)ans=mul(ans,p);
        p=mul(p,p);
        k>>=1;
    }
    cout<<ans.a[0][0];
}
il ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    n=gcd(n,m);
    if(n<=2)cout<<1;
    else fast(n-2);
    return 0;
}
