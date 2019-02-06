#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e4+5;
LL cnt[maxn],num[maxn],block,res,ans1[maxn],ans2[maxn];
struct node
{
    LL l,r,num;
    friend bool operator<(const node a,const node b)
    {
        return (a.l/block)==(b.l/block)?a.r<b.r:a.l<b.l;
    }
}q[maxn];
void del(int x)
{
    LL &k=cnt[num[x]];
    k--;
    if(k>0)
        res+=k*(k-1)-(k+1)*k;
}
void add(int x)
{
    LL &k=cnt[num[x]];
    k++;
    if(k>1)
        res+=k*(k-1)-(k-1)*(k-2);
}
void print(LL a,LL b)
{
    if(a==0||b==0)
    {
        puts("0/1");
        return;
    }
    LL t=__gcd(a,b);
    printf("%lld/%lld\n",a/t,b/t);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    for(int i=1;i<=m;i++)
    {
        q[i].num=i;
        scanf("%lld%lld",&q[i].l,&q[i].r);
    }
    block=sqrt(n);
    sort(q+1,q+1+m);
    int l=1,r=0;    
    for(int i=1;i<=m;i++)    
    {
        int ql=q[i].l,qr=q[i].r;
        while(l<ql) del(l++);
        while(l>ql) add(--l);
        while(r<qr) add(++r);
        while(r>qr) del(r--);
        ans1[q[i].num]=res;
        ans2[q[i].num]=(LL)(qr-ql+1)*(qr-ql);
    }
    for(int i=1;i<=m;i++)
        print(ans1[i],ans2[i]);
    return 0;
}