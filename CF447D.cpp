#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e3+5;
LL a[N][N],c[N*N],r[N*N],ans=-0x3f3f3f3f3f3f3f3f;
priority_queue<LL>rq,cq;
int main()
{
    LL n,m,k,p;
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%I64d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        int x=0;
        for(int j=1;j<=m;j++)
            x+=a[i][j];
        rq.push(x);
    }
    for(int j=1;j<=m;j++)
    {
        int x=0;
        for(int i=1;i<=n;i++)
            x+=a[i][j];
        cq.push(x);
    }
    for(int i=1;i<=k;i++)
    {
        LL x=cq.top();
        cq.pop();
        c[i]=c[i-1]+x;
        x-=n*p;
        cq.push(x);
    }
    for(int i=1;i<=k;i++)
    {
        LL x=rq.top();
        rq.pop();
        r[i]=r[i-1]+x;
        x-=m*p;
        rq.push(x);
    }
    for(int i=0;i<=k;i++)
        ans=max(ans,r[i]+c[k-i]-p*i*(k-i));
    cout<<ans<<endl;   
}