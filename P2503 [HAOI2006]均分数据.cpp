#include <bits/stdc++.h>
using namespace std;
const double delta=0.993;
int n,m,a[30],s[30];
double f[30][30];
inline double DP()
{ 
    memset(f,127,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            for(int k=0;k<i;k++)
                f[i][j]=min(f[i][j],f[k][j-1]+(s[i]-s[k]-(double)s[n]/m)*(s[i]-s[k]-(double)s[n]/m));
    return f[n][m];
}
double ans;
inline void SA()
{ 
    double T=2000,nowans=ans;
    while (T>1e-6)
    {
        int x=0,y=0;
        while (x==y) x=rand()%n+1,y=rand()%n+1;
        swap(a[x],a[y]);
        double now=DP();
        double Delta=now-nowans;
        if(Delta<0) nowans=now;
        else if(exp(-Delta/T)*RAND_MAX>rand()) nowans=now;
        else swap(a[x],a[y]);
        ans=min(ans,nowans);
        T*=delta;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            swap(a[i],a[j]);
            ans=min(ans,DP());
            swap(a[i],a[j]);
        }   
}       
inline void solve()
{
    ans=1e10;
    SA(),SA(),SA();
}
int main()
{
    srand(132768),srand(rand()),srand(rand());
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    solve();
    if(ans/m<1e-6) printf("0.00\n");
    else printf("%.2f\n",sqrt(ans/m));
    return 0;
}