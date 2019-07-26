#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long double p[N],f[N];
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int n,k,m;
        scanf("%d%d%d",&n,&k,&m);
        for(int i=0;i<n;i++)
            scanf("%Lf",&p[i]);
        for(int i=1;i<=m;i++)
        {
            f[i]=0;
            for(int j=0;j<n;j++)
                f[i]+=p[j]*pow(f[i-1],j);
        }
        printf("Case #%d: %.6Lf\n",t,pow(f[m],k));
    }   
    return 0;
}