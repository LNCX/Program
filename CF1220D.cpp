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
    if(n==1) printf("1 %lld\n",b[1]);
    for(int i=0;i<=20;i++)
        if(ans<a[i]) ans=a[i],k=i;
    printf("%d\n",n-ans);
    for(int i=1;i<=n;i++)
        if(c[i]!=k)
            printf("%lld ",b[i]);
    puts("");
    return 0;
}