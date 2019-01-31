#include<bits/stdc++.h>
using namespace std;
long long mypow(long long a,long long b,long long m)
{
    long long ans=1,f=a;
    while(b!=0)
    {
        if(b&1==1)
            ans=ans*f%m;
        f=f*f%m;
        b>>=1;
    }
    return ans%m;
}
int main()
{
    long long a,b,m,ans;
    cin>>a>>b>>m;
    ans=mypow(a,b,m);
    printf("%lld^%lld mod %lld=%lld",a,b,m,ans);
    return 0;
}
