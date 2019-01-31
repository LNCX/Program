#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e5+5;
const int inf=0x3f3f3f3f;
int n,m;
struct node
{
    int edge_sum;
    int w[maxm];
    int to[maxm];
    int nxt[maxm];
    int head[maxm];
}a,b;
void add(int u,int v,int w,node &a)
{
    a.nxt[++a.edge_sum]=a.head[u];
    a.to[a.edge_sum]=v;
    a.w[a.edge_sum]=w;
    a.head[u]=a.edge_sum;
}
priority_queue<pair<int,int> >q;
int dis[maxn],pre[maxn],used[maxn];
void prim()
{
    dis[1]=pre[1]=0;
    q.push(make_pair(0,1));
    for(int i=1;i<=n;i++)
    {
        int x;
        do{
            x=q.top().second;q.pop();
        }while(used[x]&&q.size());
        used[x]=1;
        for(int i=a.head[x];i!=0;i=a.nxt[i])
        {
            int y=a.to[i],z=a.w[i];
            if(!used[y]&&dis[y]<z)
            {
                dis[y]=z;pre[y]=x;
                q.push(make_pair(dis[y],y));
            }
        }
        int y=pre[x],z=dis[x];
        add(x,y,z,b),add(y,x,z,b);
    }
}
void init()
{

}
int LCA(int x,int y)
{

}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z,a),add(y,x,z,a);
    }
    prim();
    init();
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
}
