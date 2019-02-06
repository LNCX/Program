#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e4+5;
LL num[maxn],block,cnt[maxn],res,ans[maxn];
struct node
{
    int l,r,num;
    friend bool operator<(const node a,const node b)
    {
        return (a.l/block)==(b.l/block)?a.r<b.r:a.l<b.l;
    }
}a[maxn];
void add(int x)
{
    cnt[num[x]]++;
    res+=2*cnt[num[x]]-1;
}
void del(int x)
{
    cnt[num[x]]--;
    res-=2*cnt[num[x]]+1;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    for(int i=1;i<=m;i++)
    {
        a[i].num=i;
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    block=sqrt(n);
    sort(a+1,a+1+m);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        int al=a[i].l,ar=a[i].r;
        while(l<al) del(l++);
        while(l>al) add(--l);
        while(r<ar) add(++r);
        while(r>ar) del(r--);
        ans[a[i].num]=res;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}