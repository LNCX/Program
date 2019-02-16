#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+5;
struct node
{
    LL id,w,mw;
    bool operator<(const node &x) const
    {
        return w<x.w;
    }
}a[maxn],b[maxn];
struct gry
{
    LL mw,id;
    bool operator<(const gry &x) const
    {
        return mw>x.mw;
    }
}s;
priority_queue<gry>q;
LL ans[maxn],cnt;
int main()
{
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL l0=0,r0=0;
    for(LL i=1;i<=n;i++)
    {
        LL l,r;
        scanf("%lld%lld",&l,&r);
        a[i-1].id=i-1,a[i-1].w=l-r0,a[i-1].mw=r-l0;
        l0=l,r0=r;
    }
    sort(a+1,a+n);
    for(LL i=1;i<=m;i++)
        scanf("%lld",&b[i].w),b[i].id=i;
    sort(b+1,b+1+m);
    if(n-1>m)
    {
        puts("No");
        return 0;
    }
    LL pos=1;
    for(LL i=1;i<=m;i++)
    {
        while(pos<n&&a[pos].w<=b[i].w&&b[i].w<=a[pos].mw)
        {
            q.push((gry){a[pos].mw,a[pos].id});
            pos++;
        }
        if(q.empty()) continue;
        gry s=q.top();q.pop();
        if(s.mw<b[i].w)
        {
            puts("No");
            return 0;
        }
        cnt++;
        ans[s.id]=b[i].id;
    }
    if(cnt<n-1)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    for(LL i=1;i<n;i++)
        printf("%lld ",ans[i]);
    return 0;
}