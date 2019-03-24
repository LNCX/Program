#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const double eps=1e-7;
int n,m,a[maxn],b[maxn];
bool check(double x)
{
    for(int i=1;i<n;i++)
    {
        x-=(double)(x+m)/a[i];
        x-=(double)(x+m)/b[i+1];
        if(x<0) return false;
    }
    x-=(double)(x+m)/a[n];
    x-=(double)(x+m)/b[1];
    if(x>0) return true;
    else return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    double l=0,r=1e10+5;
    while(l+eps<r)
    {
        double mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(l>1e9+5) puts("-1");
    else printf("%lf\n",l);
    return 0;
}