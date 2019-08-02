#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int ch[N<<5][2],t[N],sum[N<<5],cnt;
void update(int pre,int &k,int l,int r,int x)
{
	if(l>x||r<x) return ;
	k=++cnt;
	ch[k][0]=ch[pre][0],ch[k][1]=ch[pre][1],sum[k]=sum[pre]+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	update(ch[pre][0],ch[k][0],l,mid,x);
	update(ch[pre][1],ch[k][1],mid+1,r,x);
}
int query(int u,int v,int l,int r,int k)
{
	if(l==r) return l;
	int x=sum[ch[v][0]]-sum[ch[u][0]],mid=(l+r)>>1;
	if(k<=x) return query(ch[u][0],ch[v][0],l,mid,k);
	else return query(ch[u][1],ch[v][1],mid+1,r,k-x);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(b+1,b+1+m,a[i])-b;
		update(t[i-1],t[i],1,m,x);
	}
	while(q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",b[query(t[l-1],t[r],1,m,k)]);
	}
	return 0;
}