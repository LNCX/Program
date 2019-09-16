#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,r,f[N];
struct node
{
    int l,r,e;
    bool operator<(const node &k) const
    {
        return r<k.r;
    }
}a[N];
int find(int x)
{
    a[0].r=-0x3f3f3f3f;
    for(int i=m;i>=0;i--)
        if(a[i].r+r<=a[x].l)
            return i;
}
int main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].e);
    sort(a+1,a+1+m);    
    for(int i=1;i<=m;i++)
    {
        int j=find(i);
        f[i]=max(f[i-1],f[j]+a[i].e);
    }
    cout<<f[m]<<endl;
    return 0;
}