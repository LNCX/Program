
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=3e5+5;
LL a[maxn],tot,ans[maxn];
struct node
{
    LL id,num;
    bool operator<(const node &x) const
    {
        return num<x.num;
    }
}b[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i].num=a[i],b[i].id=i;
    }
    sort(b+1,b+1+n);
    for(int i=2;i<=n;i++)
        if(b[i].num<=b[i-1].num)
            b[i].num=b[i-1].num+1;
    for(int i=1;i<=n;i++)
        ans[b[i].id]=b[i].num;
    for(int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}