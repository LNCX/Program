#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,sum,cnt,maxx;
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%lld",&x);
        sum+=x,maxx=max(x,maxx);
    }    
    (sum%2==1||(sum-maxx)<maxx)?puts("NO") :puts("YES");
    return 0;
}