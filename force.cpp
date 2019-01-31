#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int num[maxn];
struct node
{
    int d,l,r;
}a[maxn];
int n,m,ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].d,&a[i].l,&a[i].r);
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=a[i].l;j<=a[i].r;j++)
            if((num[j]-=a[i].d)<0) 
                flag=false;
        if(flag) continue;
        for(int j=a[i].l;j<=a[i].r;j++)
            num[j]+=a[i].d;
        ans++;
    }
    ans==0?puts("0"):printf("-1\n%d\n",ans);
    return 0;
}