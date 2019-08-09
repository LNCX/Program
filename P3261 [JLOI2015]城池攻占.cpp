#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    arg=x*f;
    read(args...);
}
vector<int>e[N];
int n,m,ans1[N],ans2[N];
int ch[N][2],rt[N],dis[N];
ll mul[N],add[N],dep[N],a[N],h[N],v[N],c[N],val[N];
void down(int x,ll y,ll z)
{
	if(!x) return;
	val[x]*=y,val[x]+=z;
	mul[x]*=y,add[x]*=y,add[x]+=z;
}
void pushdown(int x)
{
	down(ch[x][0],mul[x],add[x]);
	down(ch[x][1],mul[x],add[x]);
	mul[x]=1,add[x]=0;
}
int merge(int x,int y)
{
	if(!x||!y) return x|y;
	pushdown(x);pushdown(y);
	if(val[x]>val[y]) swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	if(dis[ch[x][0]]<dis[ch[x][1]]) 
        swap(ch[x][0],ch[x][1]);
	dis[x]=dis[ch[x][1]]+1;
	return x;
}
int pop(int x){return merge(ch[x][0],ch[x][1]);}
void dfs(int u)
{
	for(auto v:e[u])
    {
		dep[v]=dep[u]+1;
		dfs(v);
		rt[u]=merge(rt[u],rt[v]);
	}
	while(rt[u]&&val[rt[u]]<h[u])
    {
		pushdown(rt[u]);
		ans1[u]++;
        ans2[rt[u]]=dep[c[rt[u]]]-dep[u];
		rt[u]=pop(rt[u]);
	}
	if(a[u]) down(rt[u],v[u],0);
	else down(rt[u],1,v[u]);
}
int main()
{
    read(n,m);
	for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
	for(int i=2;i<=n;i++)
    {
        int f;
        read(f,a[i],v[i]);
        e[f].push_back(i);
    }
	for(int i=1;i<=m;i++)
    {
        read(val[i],c[i]);
		mul[i]=1;
		rt[c[i]]=merge(rt[c[i]],i);
	}
    dep[1]=1,dfs(1);
	while(rt[1])
    {
		pushdown(rt[1]);
		ans2[rt[1]]=dep[c[rt[1]]];
		rt[1]=pop(rt[1]);
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans1[i]);
	for(int i=1;i<=m;i++) printf("%d\n",ans2[i]);
	return 0;
}