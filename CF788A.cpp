#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL a[maxn],sum[maxn],ans=-0x7ffffffffffffff;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
        sum[i]=abs(a[i]-a[i+1]);
    LL tmp1=0,tmp2=0;
    for(int i=1;i<n;i++)
    {
        if(i%2) tmp1+=sum[i],tmp2-=sum[i];
        else tmp1-=sum[i],tmp2+=sum[i];
        ans=max(tmp1,ans);
        ans=max(tmp2,ans);
        if(tmp1<0) tmp1=0;
        if(tmp2<0) tmp2=0;
    }
    cout<<ans<<endl;
}