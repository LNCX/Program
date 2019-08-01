#include<cstdio>
using namespace std;
const int maxn=20e5+5;
int n,m;
long long a[maxn],add[maxn],mul[maxn],sum[maxn];
void down(int k,int l,int r,int mid)
{
    if(add[k]==0&&mul[k]==1) return;
    sum[k<<1]=(sum[k<<1]+add[k]*(mid-l+1));
    add[k<<1]=(add[k<<1]+add[k]); 
    sum[k<<1|1]=(sum[k<<1|1]+add[k]*(r-mid));
    add[k<<1|1]=(add[k<<1|1]+add[k]);
    add[k]=0;
}
void Add(int k,int l,int r,int x,int y,long long w)
{
    if(x<=l&&r<=y) 
    {
        add[k]=(add[k]+w);
        sum[k]=(sum[k]+(r-l+1)*w);
        return ;
    } 
    int mid=(l+r)>>1;
    down(k,l,r,mid);
    if(x<=mid) Add(k<<1,l,mid,x,y,w);
    if(mid<y)  Add(k<<1|1,mid+1,r,x,y,w);
    sum[k]=(sum[k<<1]+sum[k<<1|1]);
}
long long query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y) return sum[k];
    int mid=(l+r)>>1;
    long long res=0;
    down(k,l,r,mid);
    if(x<=mid) res=(res+query(k<<1,l,mid,x,y));
    if(mid<y)  res=(res+query(k<<1|1,mid+1,r,x,y));
    return res;
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--)
    {
        int q,x,y;
        long long w;
        scanf("%d",&q);
        if(q==1)
        {
            scanf("%d%d%lld",&x,&y,&w);
            Add(1,1,n,x,y,w);
        }
        else
        {
        	scanf("%d",&x);
        	printf("%lld\n",query(1,1,n,x,x));
		}
    }
    return 0;
}