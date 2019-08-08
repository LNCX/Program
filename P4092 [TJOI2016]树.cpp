#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int head[N],tot,f[N],fa[N],cnt[N];
struct edge{int nxt,to;}e[N<<1];
struct query{char s;int x;};
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
vector<query>q;
vector<int>ans; 
void dfs(int u,int father)
{
    fa[u]=father;
    if(!f[u]) f[u]=f[father];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==father) continue;
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
    f[1]=cnt[1]=1;
    while(Q--)
    {
        int x;
        char s[2];
        scanf("%s%d",s,&x);
        q.push_back((query){*s,x});
        if(*s=='C')f[x]=x,cnt[x]++;
    }
    dfs(1,0);
    reverse(q.begin(),q.end());
    for(auto k:q)
    {
        int x=k.x;
        if(k.s=='Q') ans.push_back(find(x));
        else
        {
            if(cnt[x]>1)cnt[x]--;
            else f[x]=find(fa[x]);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans) printf("%d\n",i);
    return 0;
}