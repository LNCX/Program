//
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,maxm=2e5+5;
int head[N],nxt[maxm],to[maxm],tot,vis[N];
void add(int u,int v)
{
    nxt[++tot]=head[u];
    to[tot]=v;
    head[u]=tot;
}
priority_queue<int>q;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    q.push(-1);vis[1]=1;
    while(!q.empty())
    {
        int u=-q.top();q.pop();
        printf("%d ",u);
        for(int i=head[u];i!=0;i=nxt[i])
        {
            int v=to[i];
            if(!vis[v])
            {
                q.push(-v);
                vis[v]=1;
            }
        }
    }
    return 0;
}