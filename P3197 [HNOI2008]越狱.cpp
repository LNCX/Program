#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=100003;
inline LL power(LL a,LL b)
{
    a%=mod;
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(a*ans)%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    LL m,n;
    cin>>m>>n;
    cout<<(power(m,n)-(m*power(m-1,n-1))%mod+mod)%mod<<endl;
    return 0;
}
