#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e4+5;
struct Edge
{
	int v,w,nxt;
}e[maxn<<1];
LL l=0,r=2e14+5,d[maxn][25],ans;
int head[maxn],tot,f[maxn][25],con[maxn];
int n,m,trp[maxn],son[maxn],flag,pos[maxn],res[maxn];
void add(int u,int v,int w)
{
	e[++tot].nxt=head[u];
	e[tot].v=v;
	e[tot].w=w;
	head[u]=tot;
}
void dfs1(int u,int fa,LL len)
{
	if(fa==1) flag++;
	f[u][0]=fa,d[u][0]=len;
	for(int i=0;i<=19;i++)
	{
		f[u][i+1]=f[f[u][i]][i];
		d[u][i]=d[u][i-1]+d[f[u][i-1]][i-1];
	}
	for(int i=head[u];i!=0;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u,(LL)e[i].w);
	}
}
bool search(int u,int fa)
{
	int cnt=0;
	if(con[u]) return true;
	for(int i=head[u];i!=0;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		cnt++;
		if(!search(v,u)) return false;
	}
	if(!cnt) return false; 
	return true;
}
bool check(LL t)
{
	for(int i=1;i<=n;i++)
		con[i]=pos[i]=res[i]=0;
	for(int i=1;i<=m;i++)
	{
		int tim=0,u=trp[i];
		for(int k=17;k>=0;k--)
			if(f[u][k]>=1&&tim+d[u][k]<=t)
				u=f[u][k],tim+=d[u][k];
		con[u]=1,pos[i]=u,res[i]=t-tim;
	}
	for(int i=head[1];i!=0;i=e[i].nxt)
		if(search(e[i].v,1))
		{

		}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
		scanf("%d",&trp[i]);
	dfs1(1,0,0);
	if(flag>m)
    {
        puts("-1");
        return 0;
    }
	while(l<=r)
	{
		LL mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}