#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N],cnt1,cnt2,cnt3,ans1,ans2,ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0) ans1+=-1-a[i],cnt1++;
        else if(a[i]>0) ans2+=a[i]-1,cnt2++;
        else cnt3++;
    }
    ans=ans1+ans2+cnt3+((cnt1%2!=0&&!cnt3)?2:0);
    printf("%lld\n",ans);
    return 0;
}