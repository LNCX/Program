#include<bits/stdc++.h>
using namespace std;
int n,k,ans,sum,a[100005];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        sum+=a[i];
    ans=sum;
    for(int i=k+1;i<=n;i++)
        sum-=a[i-k]-a[i],ans=max(ans,sum);
    cout<<ans<<endl;
}