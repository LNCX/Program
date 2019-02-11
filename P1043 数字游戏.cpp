#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[105];
int ma=-1<<30,mi=1<<30;
int cal(int x){return (x%10+10)%10;}
void dfs(int now,int sum,int k)
{
    if(sum*pow(9,k)<=ma&&sum>=mi) return;
    if(k==1)
    {
        sum*=cal(a[t]-a[now-1]);
        ma=max(ma,sum);
        mi=min(mi,sum);
        return;
    }
    for(int i=now;i<=t-k+1;++i)
        dfs(i+1,sum*cal(a[i]-a[now-1]),k-1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]),a[i+n]=a[i];
    for(int i=1;i<=n*2;i++) a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
    {
        t=i+n-1;
        dfs(i,1,m);
    }
    printf("%d\n%d",mi,ma);
    return 0;
}