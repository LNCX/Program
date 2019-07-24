#include<bits/stdc++.h>
#define inf 100000000000000LL
#define pa pair<int,int>
#define ll long long 
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int m,n,cnt,mx;
int q[100005],top;
int S[100005],E[100005],P[100005],disc[100005];
int root[100005],size[20000005],a[20000005][2];
ll sum[20000005];
int insert(int x,int val,int f)
{
	if(!x)x=++cnt;
	size[x]+=f;sum[x]+=f*disc[val];
	int tmp=x;
	int l=1,r=2*m;
	while(l!=r)
	{
		int mid=(l+r)>>1,t=0;
		if(val>mid)t^=1,l=mid+1;
		else r=mid;
		if(!a[x][t])a[x][t]=++cnt;
		x=a[x][t];size[x]+=f;
		sum[x]+=f*disc[val];
	}
	return tmp;
}
void update(int x,int val,int f)
{
	for(int i=x;i<=n;i+=i&-i)
		root[i]=insert(root[i],val,f);
}
ll query(int x,int K)
{
	ll ans=0,tot=0;
	top=0;
	for(int i=x;i;i-=i&-i)
	{
		q[++top]=root[i],tot+=size[root[i]];
		ans+=sum[root[i]];
	}
	if(K>tot)return ans;
	else ans=0;
	int l=1,r=2*m;
	while(l!=r)
	{
		int mid=(l+r)>>1,t,tmp=0;
		for(int i=1;i<=top;i++)
			tmp+=size[a[q[i]][0]];
		if(tmp<K)
		{
			for(int i=1;i<=top;i++)ans+=sum[a[q[i]][0]];
			t=1;
			K-=tmp,l=mid+1;
		}
		else r=mid,t=0;
		for(int i=1;i<=top;i++)
			q[i]=a[q[i]][t];
	}
	ans+=1LL*K*disc[l];
	return ans;
}
int main()
{
	m=read();n=read();
	for(int i=1;i<=m;i++)
	{
		S[i]=read(),E[i]=read(),P[i]=read();
		disc[i]=P[i];
	}
	sort(disc+1,disc+m+1);
	for(int i=1;i<=m;i++)
	{
        P[i]=lower_bound(disc+1,disc+m+1,P[i])-disc;
		update(S[i],P[i],1),update(E[i]+1,P[i],-1);
    }
	ll Pre=1,X,A,B,C,K;
	for(int i=1;i<=n;i++)
	{
		X=read();A=read();B=read();C=read();
		K=1+(A*Pre+B)%C;
		Pre=query(X,K);
		printf("%lld\n",Pre);
	}
	return 0;
}