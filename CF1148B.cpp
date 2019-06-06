#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn],cnt[maxn],ans=0;
int main()
{
    int n,m,ta,tb,k;
    scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=ta;
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    if(n<=k||m<=k||a[1]>b[m])
    {
        puts("-1");
        return 0;
    }
    int pos=1;
    for(int i=0;i<=k;i++)
    {
        int l=pos;
        while(b[l]<a[i+1]) l++;
        pos=l;
        l+=k-i;
        while(l<=m)
        {
            if(b[l]>=a[i])
                break;
            else l++;
        }
        if(l>m)
        {
            puts("-1");
            return 0;
        }
        ans=max(b[l],ans);
    }
    cout<<ans+tb<<endl;
    return 0;
}