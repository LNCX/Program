#include<bits/stdc++.h>
using namespace std;
const long long N=5e4+5;
struct Query
{
    long long op,l,r,k,id;
}q[N],ql[N],qr[N];
long long n,m,tot,ans[N],tag[N<<2],sum[N<<2],rec[N<<2];
void pushdown(long long k,long long l,long long r)
{
    if (rec[k])
    {
        rec[k]=0;
        rec[k<<1]=rec[k<<1|1]=1;
        sum[k<<1]=sum[k<<1|1]=0;
        tag[k<<1]=tag[k<<1|1]=0;
    } 
    if(tag[k])
    {
        long long mid=(l+r)>>1;
        tag[k<<1]+=tag[k],tag[k<<1|1]+=tag[k];
        sum[k<<1]+=(mid-l+1)*tag[k];
        sum[k<<1|1]+=(r-mid)*tag[k];
        tag[k]=0;
    }
}       
void add(long long k,long long l,long long r,long long x,long long y)
{
    if(x>r||y<l) return;
    if(x<=l&&r<=y)
    {
        tag[k]+=1;
        sum[k]+=(r-l+1);
        return ;
    }
    pushdown(k,l,r);
    long long mid=(l+r)>>1;
    add(k<<1,l,mid,x,y);
    add(k<<1|1,mid+1,r,x,y);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
long long query(long long k,long long l,long long r,long long x,long long y)
{
    if(x<=l&&r<=y) return sum[k];
    pushdown(k,l,r);
    long long mid=(l+r)>>1;
    long long res=0;
    if(x<=mid) res+=query(k<<1,l,mid,x,y);
    if(y>mid ) res+=query(k<<1|1,mid+1,r,x,y); 
    return res;
}
void CDQ(long long l,long long r,long long L,long long R)
{
    if(L>R) return;
    if(l==r)
    {
        for(long long i=L;i<=R;i++)
            if(q[i].op==2)
                ans[q[i].id]=l;
        return ;
    }
    long long mid=(l+r)>>1,cnt1=0,cnt2=0;
    rec[1]=1,tag[1]=sum[1]=0;
    for(long long i=L;i<=R;i++)
    {
        if(q[i].op==1)
        {
            if(q[i].k>mid)
            {
                add(1,1,n,q[i].l,q[i].r);
                qr[++cnt2]=q[i];
            }
            else ql[++cnt1]=q[i];
        }
        else
        {
            long long x=query(1,1,n,q[i].l,q[i].r);
            if(x<q[i].k)
            {
                q[i].k-=x;
                ql[++cnt1]=q[i];
            }
            else qr[++cnt2]=q[i];
        }
    }
    for(long long i=1;i<=cnt1;i++) q[L+i-1]=ql[i];
    for(long long i=cnt1+1;i<=cnt1+cnt2;i++) q[L+i-1]=qr[i-cnt1];
    CDQ(l,mid,L,L+cnt1-1);
    CDQ(mid+1,r,L+cnt1,R);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=m;i++)
    {
        long long op,l,r,k;
        scanf("%lld%lld%lld%lld",&op,&l,&r,&k);
        if(op==1) q[i]=(Query){op,l,r,k,i};
        else q[i]=(Query){op,l,r,k,++tot};
    }
    CDQ(-n,n,1,m);
    for(long long i=1;i<=tot;i++)
        printf("%lld\n",ans[i]);
    return 0;
}