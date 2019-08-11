#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node
{
    int l,r;
    bool operator<(const node &k) const
    {
        return l<k.l;
    }
}a[N];
int f[N];
vector<int>b[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].r=a[i].l+a[i].r-1;
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++)
        b[a[i].l].push_back(a[i].r);
    for(int i=n;i>=1;i--)
    {
        if(!b[i].empty()) 
            for(auto j:b[i])
                f[i]=max(f[i],f[j+1]);
        else f[i]=f[i+1]+1;
    }
    printf("%d\n",f[1]);
    return 0;
}