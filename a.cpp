#include<bits/stdc++.h>
#define dis(x0,y0,x1,y1) ((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1))
using namespace std;
const int maxn=1e5+5;
struct node
{
    int r0,r1;
    bool operator<(const node x)
    {
        return r0<x.r0;
    }
}p[maxn];
int mx[maxn],ans=0x7fffffff;
int main()
{
    int x0,y0,x1,y1,n,r0=0,r1=0;
    scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&n);
    for(int i=1;i<=n;i++)
    { 
        int x,y;
        scanf("%d%d",&x,&y);
        p[i].r0=dis(x,y,x0,y0);
        p[i].r1=dis(x,y,x1,y1);
    }
    sort(p+1,p+1+n);
    for(int i=n;i>=1;i--)
        mx[i]=max(mx[i+1],p[i].r1);
    for(int i=1;i<=n;i++)
    {
        int k=i+1;
        while(p[k].r0==p[i].r0&&k<=n)
            k++;
        int now=p[i].r0+mx[k];
        if(now<ans)
            ans=now;
    }
    cout<<ans<<endl;
    return 0;
}