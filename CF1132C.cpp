#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
struct node
{
    int l,r;
}a[maxn];
int cnt[maxn],ans,sum[maxn];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        for(int j=a[i].l;j<=a[i].r;j++)
            cnt[j]++;
    }
    for(int x=1;x<=q;x++)
    {
        int tot=0;
        for(int i=a[x].l;i<=a[x].r;i++)
            cnt[i]--;
        for(int i=1;i<=n;i++)//考虑差分
        {
            if(cnt[i]>0) tot++;
            if(cnt[i]==1) sum[i]=1;
            else sum[i]=0;
            sum[i]+=sum[i-1];
        }
        for(int y=1;y<=q;y++)
        {
            if(y==x) continue;
            ans=max(ans,tot-(sum[a[y].r]-sum[a[y].l-1]));    
        }
        for(int i=a[x].l;i<=a[x].r;i++)
            cnt[i]++;
    }
    cout<<ans<<endl;
    return 0;
}