#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int n,m;
long long mod,a[N],add[N],mul[N],sum[N];
void down(int k,int l,int r,int mid)
{
	if(add[k]==0&&mul[k]==1) return;
	sum[k<<1]=(sum[k<<1]*mul[k]+add[k]*(mid-l+1))%mod;
	mul[k<<1]=(mul[k<<1]*mul[k])%mod;
	add[k<<1]=(add[k<<1]*mul[k]+add[k])%mod; 
	sum[k<<1|1]=(sum[k<<1|1]*mul[k]+add[k]*(r-mid))%mod;
	mul[k<<1|1]=(mul[k<<1|1]*mul[k])%mod;
	add[k<<1|1]=(add[k<<1|1]*mul[k]+add[k])%mod;
	mul[k]=1;add[k]=0;
}
void Mul(int k,int l,int r,int x,int y,long long w)
{
	if(x<=l&&r<=y) 
	{
		sum[k]=(sum[k]*w)%mod;
		mul[k]=(mul[k]*w)%mod;
		add[k]=(add[k]*w)%mod;
		return ;
	}
	int mid=(l+r)>>1;
	down(k,l,r,mid);	
	if(x<=mid) Mul(k<<1,l,mid,x,y,w);
	if(mid<y)  Mul(k<<1|1,mid+1,r,x,y,w);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
}
void Add(int k,int l,int r,int x,int y,long long w)
{
	if(x<=l&&r<=y) 
	{
		add[k]=(add[k]+w)%mod;
		sum[k]=(sum[k]+(r-l+1)*w)%mod;
		return ;
	} 
	int mid=(l+r)>>1;
	down(k,l,r,mid);
	if(x<=mid) Add(k<<1,l,mid,x,y,w);
	if(mid<y)  Add(k<<1|1,mid+1,r,x,y,w);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
}
long long query(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return sum[k]%mod;
	int mid=(l+r)>>1;
	long long res=0;
	down(k,l,r,mid);
	if(x<=mid) res=(res+query(k<<1,l,mid,x,y))%mod;
	if(mid<y)  res=(res+query(k<<1|1,mid+1,r,x,y))%mod;
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
	scanf("%d%lld",&n,&mod);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<N;i++) mul[i]=1;
	scanf("%d",&m);
	build(1,1,n);
	while(m--)
	{
		int q,x,y;
		long long w;
		scanf("%d%d%d",&q,&x,&y);
		if(q==1)
		{
			scanf("%lld",&w);
			Mul(1,1,n,x,y,w);
		}
		else if(q==2)
		{
			scanf("%lld",&w);
			Add(1,1,n,x,y,w);
		}
		else printf("%lld\n",query(1,1,n,x,y));
	}
	return 0;
}
