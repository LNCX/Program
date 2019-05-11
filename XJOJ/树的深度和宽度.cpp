#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
struct edge
{
    int nxt,to;
}e[maxn<<1];
int head[maxn],tot,f[maxn],dep[maxn],cnt[maxn];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
    e[++tot]=(edge){head[v],u};
    head[v]=tot;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    cnt[dep[u]]++;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v!=fa) dfs(v,u);
    }
}
int main()
{
    int n;
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++)
    {
        string line;
        getline(cin,line);
        stringstream ss(line);
        int u,v;
        ss>>u;
        while(ss>>v) 
        {
            f[v]=u;
            add(u,v);
        }
    }
    for(int i=1;i<=n;i++)
        if(!f[i])
            dfs(i,0);
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        ans1=max(dep[i],ans1);
        ans2=max(cnt[i],ans2);
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
