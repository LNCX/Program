//暴力踩标算,n方过百万
#pragma GCC optimize("O2")
#include<queue>
#include<cstdio>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
const LL oo=1e15;
LL read()
{
    LL x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
LL t,n,k;
struct lap
{
    LL c,f;
    bool operator<(const lap &x) const
    {
        return c/f>x.c/x.f;
    }
}a[maxn],b[maxn];
bool check(LL add)
{
    priority_queue<lap>q;
    for(int i=1;i<=n;i++)
        q.push(a[i]);
    for(int i=1;i<=k;i++)
    {
        if(q.empty()) return true;
        lap x=q.top();q.pop();
        if(x.c/x.f<i-1) return false;//考虑每段时间的开头即可
        if(x.c/x.f>=k)   return true;
        x.c+=add;q.push(x);
    }
    return true;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        a[i].c=read();
    for(int i=1;i<=n;i++)
        a[i].f=read();
    LL l=0,r=oo,ans=-1;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}
