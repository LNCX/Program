#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],b[N],c[N],n,ans,k;
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        int t=0,x=b[i];
        while(x%2==0&&x) x>>=1ll,t++;
        a[t]++,c[i]=t;
    }
    for(int i=0;i<=100;i++)
        if(ans<a[i]) ans=a[i],k=i;
    printf("%lld\n",n-ans);
    for(int i=1;i<=n;i++)
        if(c[i]!=k)
            printf("%lld ",b[i]);
    puts("");
    return 0;
}