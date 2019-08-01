#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e5;
struct point
{
    int x,y,f[5];
}a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {   
        int n;
        int l=-inf,u=inf,r=inf,d=-inf;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
            for(int j=1;j<=4;j++)
            {
                int x;
                scanf("%d",&x);
                a[i].f[j]=(x==0);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].f[1]) l=max(a[i].x,l);
            if(a[i].f[2]) u=min(a[i].y,u);
            if(a[i].f[3]) r=min(a[i].x,r);
            if(a[i].f[4]) d=max(a[i].y,d);
        }
        if(l>r||d>u) puts("0");
        else printf("1 %d %d\n",l,u);
    }
    return 0;
}