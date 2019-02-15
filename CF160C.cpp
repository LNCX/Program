#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn=1e5+5;
LL a[maxn]={0x7fffffffffffffff},b[maxn],c[maxn],tot;
int main()
{
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        c[i]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            b[++tot]=a[i];
        else c[tot]++;
    }
    for(int i=1;i<=tot;i++)
    {
        if(c[i]*n<k) 
            k-=c[i]*n;
        else
        {
            printf("%lld ",b[i]);
            for(int j=1;j<=tot;j++)
            {
                if(c[j]*c[i]<k)
                    k-=c[j]*c[i];
                else
                {
                    printf("%lld",b[j]);
                    return 0;
                }
            }
        }
    }
    return 0;
}
