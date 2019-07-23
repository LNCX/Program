#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int x,y,v;
    bool operator<(const node &a) const
    {
        return v>a.v;
    }
}a[2057];
int main()
{
    int n,m,cnt=0,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[++cnt].v);
            a[cnt].x=i;a[cnt].y=j;
        }
    sort(a+1,a+cnt+1);
    int sum=0,ans=0;
    for(int i=1;i<=cnt;i++)
    {
        if(sum+abs(a[i-1].x-a[i].x)+abs(a[i-1].y-a[i].y)+a[i].x+1>k)
            break;
        if(i!=1)
            sum+=abs(a[i-1].x-a[i].x)+abs(a[i-1].y-a[i].y)+1,ans+=a[i].v;
        else if(i==1&&a[i].x <= k) 
            sum+=a[i].x+1,ans+=a[i].v;
    }
    cout<<ans<<endl;
    return 0;
}
