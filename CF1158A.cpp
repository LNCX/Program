#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn],b[maxn],g[maxn],ans;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    if(a[n]>b[m])
    {
        puts("0");
        return 0;
    }
    int l=1;
    for(int i=1;i<=n;i++)
    {
        
    }
    return 0;
}