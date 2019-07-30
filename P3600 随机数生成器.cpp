#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=666623333,N=2011;
int n,X,q,s[N],top,L[N],R[N];
ll f[N],ans,invp[N];
struct line
{
    int l,r;
    bool operator<(const line k) const
    {
        if(l==k.l) return r>k.r;
        else return l<k.l;
    }
}a[N];
ll power(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod,b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&X,&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+q+1);
    for(int i=1;i<=q;i++)
    {
        while(a[i].r<=a[s[top]].r) top--;
        s[++top]=i;
    }
    q=top;
    for(int i=1;i<=q;i++) a[i]=a[s[i]];
    int head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        while(tail<q && a[tail+1].l<=i) tail++;
        while(head<=tail && a[head].r<i) head++;
        L[i]=head;
        R[i]=tail;
    }
    for(int x=1;x<=X;x++)
    {
        ll sum,p,np,fp,leip;
        int j=0;
        sum=1;
        p=(x-1+mod)%mod*power(X,mod-2);
        p%=mod;
        np=(1-p+mod)%mod;
        fp=power(np,mod-2);
        invp[0]=1;
        f[0]=1;
        leip=1;
        for(int i=1;i<=n;i++) invp[i]=1LL*invp[i-1]*fp%mod;
        for(int i=1;i<=n;i++)
        {
            while(j<i && R[j]<L[i]-1) sum-=1LL*f[j]*invp[j]%mod,sum+=mod,sum%=mod,j++;
            f[i]=sum*leip%mod*p%mod;
            leip=leip*np%mod;
            sum+=1LL*f[i]*invp[i];
            sum%=mod;
        }
        ll tot=0;
        leip=1;
        for(int i=n;i>=1;i--,leip=1LL*leip*np%mod) if(R[i]==q) tot+=f[i]*leip%mod,tot%=mod;
        else break;
        ans+=(1-tot+mod)%mod;
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}