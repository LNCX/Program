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
            ll x=a[i],q=10,qq=1,w=0;
			while(x)
            {
				int y=x%10;w++;
				ans=(ans+q*y%mod*cnt[j])%mod;
				ans=(ans+qq*y%mod*cnt[j])%mod;
				if(w<j)q=100*q%mod;else q=10*q%mod;
				if(w<=j)qq=100*qq%mod;else qq=10*qq%mod;
				x/=10;
			}
        }
    cout<<ans<<endl;
    return 0;
}