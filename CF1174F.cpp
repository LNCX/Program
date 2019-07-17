#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct edge
{
    int nxt,to;
}e[N<<1];
int head[N],tot,dep[N]={-1},f[N],size[N],top[N],son[N];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void dfs(int u,int fa)
{
    f[u]=fa;
    size[u]=1;
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
}
void dfs(int u)
{
    if(son[u])
    {
        top[son[u]]=top[u];
        dfs(son[u]);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            top[v]=v;
            dfs(v);
        }
    }
}
int lx;
int ask(char c,int x)
{
    int res;
    printf("%c %d\n",c,x);
    fflush(stdout);
    scanf("%d",&res);
    return res;
}
void init()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,0);
    top[1]=1;
    dfs(1);
    puts("d 1");
    fflush(stdout);
    scanf("%d",&lx);
}
int solve(int u)
{
    vector<int>h;
    for(int v=u;v!=0;v=son[v])
        h.push_back(v); 
    int ly=(lx+dep[h.back()]-ask('d',h.back()))/2,y=h[ly-dep[u]];
    if(lx==ly) return y;
    return solve(ask('s',y));
}
int main()
{
    init();
    printf("! %d\n",solve(1)); 
    return 0;
}