#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int a[maxn],p[maxn],ans[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        for(int j=2;j*j<=abs(a[i]);j++)
            while(!(a[i]%(j*j)))
                a[i]/=j*j;
        p[i]=a[i];
    }
    sort(p+1,p+n+1);
    int cnt=unique(p+1,p+n+1)-(p+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(p+1,p+cnt+1,a[i])-p;
    int id=lower_bound(p+1,p+cnt+1,0)-p;
    if(p[id])
        id=-1;
    for(int i=1;i<=n;i++) 
    {
        int now=0;
        memset(p,0,sizeof(p));
        for(int j=i;j<=n;j++) 
        {
            if(a[j]!=id&&!p[a[j]])
                now++;
            p[a[j]]=1;
            ans[max(now,1)]++;
        }
    }
    for(int i=1;i<n;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}