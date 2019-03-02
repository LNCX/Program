#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL n,x1,x2;
pair<LL,LL>a[maxn];
int main()
{
    scanf("%lld%lld%lld",&n,&x1,&x2);
    for(int i=1;i<=n;i++)
    {
        LL k,b;
        scanf("%lld%lld",&k,&b);
        a[i]=make_pair(k*x1+b,k*x2+b);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
        if(a[i].second>a[i+1].second&&a[i].first<a[i+1].first)
            {
                puts("YES");
                return 0;
            }
    puts("NO");
    return 0;
}