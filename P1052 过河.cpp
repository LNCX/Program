#include<bits/stdc++.h>
using namespace std;
const int mod=2520,N=3e5+5,inf=0x3f3f3f3f;
int a[N],f[N],d[N],v[N],ans=inf;
int main()
{
    int n,s,t,m;
    scanf("%d%d%d%d",&n,&s,&t,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++) d[i]=(a[i]-a[i-1])%mod;
    for(int i=1;i<=m;i++) a[i]=a[i-1]+d[i],v[a[i]]=1;
    n=a[m];
    for(int i=1;i<=n+t;i++)
    {
        f[i]=inf;
        for(int j=s;j<=t;j++)
            if(i>=j)
                f[i]=min(f[i],f[i-j]);
        f[i]+=v[i];
    }
    for(int i=n;i<=n+t;i++)
        ans=min(ans,f[i]);
    printf("%d\n",ans);
}