#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,siz[N<<2],sum[N<<2],add[N<<2];
void down(int k)
{
    if(add[k]==0) return ;
    add[k]=0;
    add[k<<1]^=1,add[k<<1|1]^=1;
    sum[k<<1]=siz[k<<1]-sum[k<<1];
    sum[k<<1|1]=siz[k<<1|1]-sum[k<<1|1];
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        siz[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    siz[k]=siz[k<<1]+siz[k<<1|1];
}
void fix(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
    {
        add[k]^=1;
        sum[k]=siz[k]-sum[k];
        return;
    }
    int mid=(l+r)>>1;
    down(k);
    if(x<=mid) fix(k<<1,l,mid,x,y);
    if(y>mid ) fix(k<<1|1,mid+1,r,x,y);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
int query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
        return sum[k];
    int mid=(l+r)>>1;
    down(k);
    int res=0;
    if(x<=mid) res+=query(k<<1,l,mid,x,y);
    if(y>mid ) res+=query(k<<1|1,mid+1,r,x,y);
    return res;
}
int main()
{
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int c,a,b;
        scanf("%d%d%d",&c,&a,&b);
        if(c==0) fix(1,1,n,a,b); 
        if(c==1) printf("%d\n",query(1,1,n,a,b));
    }
    return 0;
}