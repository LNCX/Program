#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
    int q;
    scanf("%lld",&q);
    while(q--)
    {
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",min({(a+b+c)/3,a,b}));  
    }
    return 0;
}