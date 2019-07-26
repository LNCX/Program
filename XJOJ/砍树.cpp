#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+5;
struct node
{
    long long p,h;
    bool operator<(const node k) const
    {
        if(p!=k.p) return p<k.p;
        return h<k.h;
    }
}a[N];
long long ans=0;
signed main()
{
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
        scanf("%d%d",&a[i].p,&a[i].h);
    if(n==1)
    {
        puts("0");
        return 0;
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)
    {
        long long cut;
        if(i==1) cut=a[i+1].p-a[i].p;
        else if(i==n) cut=a[i].p-a[i-1].p;
        else cut=min(a[i].p-a[i-1].p,a[i+1].p-a[i].p);
        if(cut<a[i].h) ans+=a[i].h-cut;
    }

    cout<<ans<<endl;
    return 0;
}