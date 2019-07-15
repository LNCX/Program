#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int head[maxn],tot,f[maxn];
struct edge{int nxt,to;}e[maxn<<1];
struct query{char s;int x;};
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
vector<query>q; 
void dfs(int u,int fa)
{
    if(!f[u]) f[u]=f[fa];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
}
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[++tot]=(edge){head[u],v},head[u]=tot;
    }
    while(Q--)
    {
        int x;
        char s[2];
        scanf("%s%d",s,&x);
        q.push_back((query){*s,x});
        f[x]=x;
    }
    dfs(1,0);
    reverse(q.begin(),q.end());
    for(auto k:q)
    {
        
    }
    return 0;
}