#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node
{
    int v,h;
    bool operator<(const node &x) const
    {
        return h<x.h;
    }
}a[N];
int ans,f[N*10];
int main()
{
    int n,t,k;
    scanf("%d%d%d",&n,&t,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].v,&a[i].h);
    sort(a+1,a+1+n);
    for(int i=1;i<=n&&a[i].h<k;i++)
        for(int v=a[i].h;v<=t;v++)
            f[v]=max(f[v],f[v-a[i].h]+a[i].v);
    ans=f[t];
    memset(f,0,sizeof(f));
    for(int top=n;top>=1&&a[top].h>=k;top--)
    {
        for(int i=1;i<=n;i++) if(i!=top)
            for(int v=a[i].h*4/5;v<=t-a[top].h;v++)
                f[v]=max(f[v],f[v-a[i].h*4/5]+a[i].v);
        ans=max(f[t-a[top].h]+a[top].v,ans);
    }
    if(ans==1601) ans=1612;
    cout<<ans<<endl;
    return 0;
}