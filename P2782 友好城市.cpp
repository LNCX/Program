#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
    int l,r;
    bool operator<(const node x)const 
    {
        return l<x.l;
    }
}a[N];
int ans,low[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n);
    low[++ans]=a[1].r;
    for(int i=2;i<=n;i++)
    {
        if(low[ans]<a[i].r) low[++ans]=a[i].r;
        else low[upper_bound(low+1,low+ans+1,a[i].r)-low]=a[i].r;
    }
    cout<<ans<<endl;
}