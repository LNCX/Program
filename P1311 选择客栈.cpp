#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int now,ans,n,k,p;
int a[maxn],b[maxn],last[maxn],sum[maxn],cnt[maxn];
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y<=p)
            now=i;
        if(now>=last[x])
            sum[x]=cnt[x];
        last[x]=i;
        ans+=sum[x];
        cnt[x]++;
    }
    cout<<ans<<endl;
    return 0;
}