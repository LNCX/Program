#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define int long long 
using namespace std;
const int N=2e5+5;
int s[N],a[N],n,c[N];
void add(int x,int y)
{
    while(x<=n)
    {
        c[x]+=y;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int find(int x)
{
    int l=1,r=n,res;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(ask(mid)>x) r=mid-1,res=mid;
        else l=mid+1;
    }
    return res;
}
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&s[i]),add(i,i);
    for(int i=n;i>=1;i--)
    {
        a[i]=find(s[i]);
        add(a[i],-a[i]);
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",a[i]);
}