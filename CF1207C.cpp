#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
char s[N];
int f[N][2];
signed main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%lld%lld%lld%s",&n,&a,&b,s+1);
        for(int i=0;i<=n;i++)
            f[i][0]=f[i][1]=0x3f3f3f3f3f3f3f3f;
        f[0][0]=b,s[n+1]='0';
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0'&&s[i+1]=='0') 
                f[i][0]=min(f[i-1][0]+a+b,f[i-1][1]+2*a+b);
            f[i][1]=min(f[i-1][0]+2*a+2*b,f[i-1][1]+a+2*b);
        }
        printf("%lld\n",f[n][0]);
    }
    return 0;
}