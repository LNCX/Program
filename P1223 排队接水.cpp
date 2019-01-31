#include<bits/stdc++.h>
using namespace std;
double ans=0;
struct node
{
    int r,t;
    bool operator <(const node &x) const
    {
        if(this->t!=x.t)
            return this->t<x.t;
        return this->r<x.r;
    }
}a[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].t);
        a[i].r=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].r);
    printf("\n");
    for(int i=1;i<=n;i++)
        ans+=i*a[n-i].t;
    ans/=n;
    printf("%.2lf",ans);
}