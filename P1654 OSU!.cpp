#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
ll a[N],x[N],y[N],f[N];
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