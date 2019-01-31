#include<bits/stdc++.h>//ss
using namespace std;
typedef long long LL;
LL b[300002],a[300002];
LL l,r;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n/2;i++)
        scanf("%lld",&b[i]);
    r=a[1]=0;
    l=a[n]=b[1];
    for(int i=2;i<=n/2;i++)
    {
        if(b[i]-r<=l)
        {
            a[i]=r;
            a[n-i+1]=b[i]-a[i];
            l=a[n-i+1];
        }
        else
        {
            a[n-i+1]=l;
            a[i]=b[i]-a[n-i+1];
            r=a[i];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",a[i]);
    printf("\n");
    return 0;
}