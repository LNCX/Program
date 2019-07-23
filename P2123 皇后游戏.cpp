#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
struct node
{
    int x,y,d;
    bool operator<(node a) const
    {
        if(d!=a.d) return d<a.d;
        if(d<=0) return x<a.x;
        return y>a.y;
    }
}a[N];
long long c[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            if(a[i].x>a[i].y) a[i].d=1;
            else if(a[i].x<a[i].y) a[i].d=-1;
            else a[i].d=0;
        }
        sort(a+1,a+n+1);
        long long s=0;
        for(int i=1;i<=n;i++)
        {
            s+=a[i].x;
            c[i]=max(c[i-1],s)+a[i].y;
        }
        printf("%lld\n",c[n]);
    }
}