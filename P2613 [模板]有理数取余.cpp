#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=19260817;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');x%=mod;c=getchar();}
    arg=x*f;
    read(args...);
}
ll power(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b)    
    {
        if(b&1) (res*=a)%=mod;
        b>>=1,(a*=a)%=mod;
    }
    return res;
}
int main()
{
    ll a,b;
    read(a,b);
    printf("%lld\n",(a*power(b,mod-2)%mod+mod)%mod);
    return 0;
}