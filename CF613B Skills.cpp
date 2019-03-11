#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
struct node
{
    ll id,v;
}a[maxn];
bool cmp(node a,node b)
{
    return a.v<b.v||a.v==b.v&&a.id<b.id;
}
ll n,A,cf,cm,m;
ll L,ans[maxn],f,ansA,ansL;
ll s[maxn];
ll findL(ll m,ll R)
{
    ll l=0,r=A,ans=0;
    while(l<=r)
    {
        ll mid=(r+l)>>1;
        int p=lower_bound(a+1,a+1+n,(node){0,mid},cmp)-a-1;
        if(p>R)p=R;
        if(p*mid-s[p]<=m)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main()
{
    scanf("%lld%lld%lld%lld%lld",&n,&A,&cf,&cm,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i].v);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i].v;
    for(int i=0;i<=n;i++) 
    {
        ll p=A*i-s[n]+s[n-i];
        if(p<=m)
        {
            L=findL(m-p,n-i);
            if(cm*L+cf*i>f) 
            {
                f=cm*L+cf*i;
                ansA=i;
                ansL=L;
            }
        }
    }
    printf("%lld\n",f);
    for(int j=1;j<=n;j++)
    {
        if(j>n-ansA)
            ans[a[j].id]=A;
        else if(a[j].v<=ansL)
            ans[a[j].id]=ansL;
        else
            ans[a[j].id]=a[j].v;
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}