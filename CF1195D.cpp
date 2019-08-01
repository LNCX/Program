#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,mod=998244353;
ll n,ans,a[N],b[N],cnt[20],p[20]={1},sum[20][20];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=18;i++)
        p[i]=(p[i-1]*10ll)%mod;
    for(int i=1;i<=n;i++)
    {
        int x=a[i],num=0;
        while(x!=0) num++,x/=10;
        cnt[b[i]=num]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=10;j++) if(cnt[j])
        {
            ll x=a[i],tmp=0;
            for(int k=0;k<j;k++,x/=10) (tmp+=cnt[j]*(x%10)*(p[2*k]+p[2*k+1]))%=mod;
            cerr<<tmp<<" ";
            (tmp+=cnt[j]*(a[i]/p[b[i]]*p[b[i]])*p[j])%=mod;
            cerr<<tmp<<endl;
            (ans+=tmp)%=mod;
        }
    cout<<ans<<endl;
    return 0;
}