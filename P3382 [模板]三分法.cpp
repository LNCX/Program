#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
const double eps=1e-6;
int n;
double l,r,c[maxn];
double calc(double x)
{
    double res=0;
    for(int i=1;i<=n+1;i++)
        res+=c[i]*pow(x,n-i+1);
    return res;
}
int main()
{
    scanf("%d%lf%lf",&n,&l,&r);
    for(int i=1;i<=n+1;i++)
        scanf("%lf",&c[i]);
    while(l+eps<r)
    {
        double mid=(l+r)/2;
        if(calc(mid+eps)>calc(mid-eps)) l=mid;
        else r=mid; 
    }
    printf("%.5lf\n",l);
    return 0;
}