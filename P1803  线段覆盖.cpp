#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node
{
    int l;
    int r;
    bool operator<(const node &x) const
    {
        return r<x.r;
    }
}a[N];
int main()
{
    int n,ans=0,x=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i].l<a[x].r)
            continue;
        x=i;
        ans++;
    }
    cout<<ans<<endl;
}