#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005;
struct node
{
    int l;
    int r;
}a[maxn];
int ans,n;
bool cmp(node x,node y)
{
    if(x.l<y.l)
        return true;
    if(x.l>y.l)
        return false;
    if(x.r<y.r)
        return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,w;
        scanf("%d%d",&x,&w);
        a[i].l=x-w;
        a[i].r=x+w;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=n;i>=1;i--)
    {
        int len=i;
        ans++;
        while(i-1<=n&&a[len].l<a[i-1].r) i--;
    } 
    cout<<ans<<endl;
    return 0;
}
