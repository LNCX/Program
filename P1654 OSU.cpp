#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
double a[maxn],x[maxn],y[maxn],f[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        x[i]=(x[i-1]+1)*a[i];
        y[i]=(y[i-1]+2*x[i-1]+1)*a[i];
        f[i]=f[i-1]+(3*y[i-1]+3*x[i-1]+1)*a[i];
    }
    printf("%.1lf\n",f[n]);
    return 0;
}