#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x;
    bool f=true;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-') f=false;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
const int N=1e4+5,maxm=1e5+5;
int n,m;
int a[N],num[N],rev[N];
struct edge
{
    int nxt,to;
}e[maxm<<1];
int head[N],tot=1;
void edge_add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
    e[++tot]=(edge){head[v],u};
    head[v]=tot;
}
void dfs1(int u,int fa)
{


}
void dfs2(int u,int fa)
{

}

void build(int k,int l,int r)
{
    if(l==r)
    {
        num[k]=a[l];
        rev[k]=a[l];
    }
}

void fix(int k,int l,int r,int x,int y,int w)
{

}
int query(int k,int l,int r,int x,int y)
{

}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        edge_add(x,y);
    }
    dfs1(1,0);
    return 0;
}