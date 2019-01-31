#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,diff[maxn],need[maxn],num[maxn];
struct node
{
    int d,l,r;
}a[maxn];
bool judge(int x)
{
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++)
    {
        diff[a[i].l]+=a[i].d;
        diff[a[i].r+1]-=a[i].d; 
    }
    for(int i=1;i<=n;i++)
    {
        need[i]=need[i-1]+diff[i];
        if(need[i]>num[i])return false;
    }
    return true;
} 
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].d,&a[i].l,&a[i].r);
    int l=1,r=m; 
    if(judge(m)){puts("0");return 0;}
    while(l<r)
    {
        int mid=(l+r)/2;
        if(judge(mid))l=mid+1;
        else r=mid;
    }
    printf("-1\n%d\n",l);
}