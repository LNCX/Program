#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q[100];
inline bool check(ll b,ll x)
{
    int len=0;
    while(x)
    {
        q[len++]=x%b;
        x/=b;
    }
    for(int i=0;i<len/2;i++)
        if(q[len-1-i]!=q[i])
            return false;
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        scanf("%lld",&x);
        int block=sqrt(x)+1;
        bool flag=true;
        for(ll i=2;i<=block&&flag;i++)
            if(check(i,x))
            {
                printf("%lld\n",i);
                flag=false;
            }
        for(ll i=block;i>=1&&flag;i--)
            if(x%i==0)
            {
                ll ans=x/i-1;
                if(ans>block)
                {
                    printf("%lld\n",ans);
                    flag=false;
                }
            }
        if(flag) printf("%lld\n",x+1);
    }    
    return 0;
}