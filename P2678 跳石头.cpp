#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5,oo=1e9;
int L,n,m,a[maxn];
bool check(int x)
{
    int l=0,cnt=0;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]-a[l]<x) cnt++;
        else l=i;
    }
    if(cnt>m) return false;
    return true;
}
int main()
{
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=L;
    int l=1,r=L,ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}