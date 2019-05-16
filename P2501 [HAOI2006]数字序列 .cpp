#include<bits/stdc++.h>
using namespace std;
using namespace std;
typedef long long LL;
const int maxn=35005,inf=0x7fffffff;
int n,f[maxn],len,head[maxn],tot,b[maxn],t[maxn];
LL g[maxn],disL[maxn],disR[maxn];
struct edge
{
    int nxt,to;
}e[maxn];
inline void add(int u,int v)
{ 
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;++i)
        scanf("%d",&x),b[i]=x-i;
    b[n+1]=inf;
    for(int i=1;i<=n+1;++i)
    {
        int l=0,r=len,mid;
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(t[mid]<=b[i]) l=mid;
            else r=mid-1;
        }
        if(l==len) ++len;
        t[l+1]=b[i]; f[i]=l+1;
    }
    b[0]=-inf; 
    memset(g,20,sizeof(g));
    add(0,0);g[0]=0;
    for(int i=1;i<=n;++i)
        add(f[i],i);
    for(int u=1;u<=n+1;++u)
    {
        for(int i=head[f[u]-1];i;i=e[i].nxt)
        {
            int v=e[i].to; if(v>=u||b[v]>b[u]) continue;
            disL[v-1]=0; for(int j=v;j<=u;++j) disL[j]=disL[j-1]+abs(b[j]-b[v]);
            disR[v-1]=0; for(int j=v;j<=u;++j) disR[j]=disR[j-1]+abs(b[j]-b[u]);
            for(int j=v-1;j<=u;++j) g[u]=min(g[u],g[v]+disL[j]-disL[v-1]+disR[u]-disR[j]);
        }
    }
    printf("%d\n%lld\n",n-len+1,g[n+1]);
    return 0;
}