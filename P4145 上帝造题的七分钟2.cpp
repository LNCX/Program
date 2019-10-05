#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=1e5+5;
int a[N];
class SegmentTree
{
private:
    int tag[N<<2],sum[N<<2];
    void pushup(int k)
    {
        tag[k]=tag[k<<1]&tag[k<<1|1];
        sum[k]=sum[k<<1]+sum[k<<1|1];
    }
public:
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            sum[k]=a[l];
            if(a[l]==1) tag[k]=1;
            return ;
        }
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(r<x||l>y) return ;
        if(l==r)
        {
            sum[k]=(int)sqrt(sum[k]);
            if(sum[k]==1) tag[k]=1;
            return ;
        }
        if(tag[k]==1) return;
        int mid=(l+r)>>1;
        update(k<<1,l,mid,x,y);
        update(k<<1|1,mid+1,r,x,y);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y) 
    {
        if(r<x||l>y) return 0;
        if(x<=l&&r<=y) return sum[k];
        int mid=(l+r)>>1;
        return query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y);
    }   
}t;
signed main()
{
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    t.build(1,1,n);
    int m;
    scanf("%lld",&m);
    for(int i=1;i<=m;i++)
    {
        int k,l,r;
        scanf("%lld%lld%lld",&k,&l,&r);
        if(l>r) swap(l,r);
        if(k==0) t.update(1,1,n,l,r);
        else printf("%lld\n",t.query(1,1,n,l,r));
    }
    return 0;
}