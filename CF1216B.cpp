#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,x,c[10000],a[10000],ans;
int cmp(int x,int y)
{
    return a[x]>a[y];
}
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) 
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        c[i]=i;
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
	    x=c[i];
	    ans=ans+a[x]*(i-1)+1;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) 
        printf("%lld ",c[i]);
}