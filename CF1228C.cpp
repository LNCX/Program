#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;
vector<int>a;
inline int power(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=a*ans%mod;
        b>>=1;a=a*a%mod;
    }
    return ans%mod;
}
void divide(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            a.push_back(i);
            while(x%i==0) x/=i;
        }
    if(x!=1)a.push_back(x);
}   
signed main()
{
    int x,n;
    scanf("%lld%lld",&x,&n);
    divide(x);
    int ans=1;
    for(auto i:a)
    {
        int x=n,cnt=0;
        while(x)
        {
            x/=i;
            cnt+=x;
        }
        (ans*=power(i,cnt))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}