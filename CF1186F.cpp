#pragma comment(linker, "/STACK:102400000,102400000") 
#include<bits/stdc++.H>
using namespace std;
const int maxn=1e6+5;
struct edge
{
    int nxt,to;
}e[maxn<<1];
int head[maxn],tot=1;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
int n,m;
int vis[maxn],in0[maxn],cut[maxn<<1],in[maxn],sum,out[maxn<<1];
void print(int u)
{
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(cut[i]||out[i]||out[i^1]) continue;
        out[i]=out[i^1]=1;
        printf("%d %d\n",u,v);
        print(v);
    }
}
void dfs(int u)
{
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]) continue;
        if(in[u]-1>=ceil((double)in0[u]/2.0)&&in[v]-1>=ceil((double)in0[v]/2.0))
        {
            cut[i]=cut[i^1]=1;
            in[u]--,in[v]--,sum--;  
            if(sum<=ceil((double)((n+m)/2.0)))
            {
                cout<<sum<<endl;
                memset(vis,0,sizeof(vis));
                for(int i=1;i<=n;i++)
                    if(!vis[i])
                        print(i);
                exit(0);
            }
        }
        dfs(v);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    sum=m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        in0[u]++,in0[v]++;
    }
    for(int i=1;i<=n;i++)
    	in[i]=in0[i];
    dfs(1);
    return 0;
}