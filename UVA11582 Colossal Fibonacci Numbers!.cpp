#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int maxn=1005;
int f[maxn*maxn]={0,1,1};
LL pow(LL a,LL b,LL p)
{
    LL ans=1;
    while(b)
    {
        if(b%2) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans%p;
}
int main()
{
    LL a,b;
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        if(n==1||a==0)
        {
            cout<<'0'<<endl;
            continue;
        }
        for(int i=3;i<=n*n+10;i++)
        {
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==f[2] && f[i-1]==f[1])
            {
                m=i-2;
                break;
            }
        }
        cout<<f[pow(a%m,b,m)]<<endl;
    }
}