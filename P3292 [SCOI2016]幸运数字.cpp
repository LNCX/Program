#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5,M=60;
int dep[N],f[N][20],n,q,head[N],tot;
ll w[N],p[N][20][M+5],s[M+5];
template <class T> inline void read(T &a)
{
    char c=getchar();
    T x=0,f=1;
    while(!isdigit(c))
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    a=x*f;
}
struct edge
{
    int nxt,to;
}e[N<<1];
inline void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
inline void insert(ll x,ll *p)
{
    if(!x) return;
    for(int i=M;i>=0;i--)
    {
        if(!(x>>i)) continue;
        if(!p[i]){p[i]=x;break;}
        else x^=p[i];
    }
}
inline void merge(ll *a,ll *b,ll *c)
{
    for(int i=0;i<=M;i++) c[i]=a[i];
    for(int i=0;i<=M;i++) insert(b[i],c);
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    insert(w[u],p[u][0]),insert(w[fa],p[u][0]);
    for(int i=1;(1<<i)<=dep[u];i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
        merge(p[u][i-1],p[f[u][i-1]][i-1],p[u][i]);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
}
inline int jump(int x,int k)
{
	for(int i=0;i<=M;i++)
		insert(p[x][k][i],s);
    return f[x][k];
}
inline void lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=15;i>=0;i--)
    {
		if(dep[f[x][i]]>=dep[y])
            x=jump(x,i);
		if(x==y) return;
	}
    for(int i=15;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=jump(x,i),y=jump(y,i);
    jump(x,0),jump(y,0);
}
int main()
{
    read(n),read(q);
    for(int i=1;i<=n;i++)
        read(w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        read(u),read(v);
        add(u,v);
    }
    dfs(1,0);
    while(q--)
    {
        int u,v;
        read(u),read(v);
        if(u==v)
        {
            printf("%lld\n",w[u]);
            continue;
        }
        memset(s,0,sizeof(s));
        lca(u,v);
        ll res=0;
        for(int i=M;i>=0;i--)
            if((res^s[i])>res)            
                res^=s[i];
        printf("%lld\n",res);
    }
    return 0;
}