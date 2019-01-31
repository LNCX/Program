#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
const int maxn=1e6+5;
int n,m;
int a[maxn],c[maxn],b[maxn],ans[maxn];
//a数组保存原数列，c树状数组，ans保存结果
struct node
{
    int l,r;
    int pos;
    bool operator<(const node &x) const
    {
        return r<x.r;
    }
}ask[maxn];
void add(int x,int w)
{
    while(x<=n)
    {
        c[x]+=w;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&ask[i].l,&ask[i].r);
        ask[i].pos=i; 
    }
    sort(ask+1,ask+1+m);
    int next=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=next;j<=ask[i].r;j++)
        {
            if(b[a[j]]) 
                add(b[a[j]],-1);
            add(j,1);
            b[a[j]]=j;
        }
        next=ask[i].r+1;
        ans[ask[i].pos]=sum(ask[i].r)-sum(ask[i].l-1);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return  0;
}