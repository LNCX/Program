#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int dis[N],ch[N*31][2],tot;
int ans,w[N],to[N],nxt[N],head[N],edge_sum;
void add(int x,int y,int z)
{
    nxt[++edge_sum]=head[x];
    head[x]=edge_sum;
    to[edge_sum]=y;
    w[edge_sum]=z;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i!=0;i=nxt[i])
    {
        int y=to[i],z=w[i];
        if(y==fa) continue;
        dis[y]=dis[u]^z;
        dfs(y,u);
    }
}
void insert(int x)
{
    int u=0;
    for(int i=1<<30;i!=0;i>>=1)
    {
        bool c=x&i;
        if(!ch[u][c])
            ch[u][c]=++tot;
        u=ch[u][c];
    }
}
int ask(int x)
{
    int ans=0,u=0;
    for(int i=1<<30;i!=0;i>>=1)
    {
        bool c=x&i;
        if(ch[u][c^1]) ans+=i,u=ch[u][c^1];
        else u=ch[u][c];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        insert(dis[i]);
    for(int i=1;i<=n;i++)
        ans=max(ans,ask(dis[i]));
    cout<<ans<<endl;
    return 0;
}