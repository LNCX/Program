#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int maxm=2e4+5;
const int inf=0x3f3f3f3f;
int nxt[maxm],to[maxm],head[maxm],w[maxm],edge_sum;
void add(int x,int y,int z)
{
    nxt[++edge_sum]=head[x];
    to[edge_sum]=y;
    w[edge_sum]=z;
    head[x]=edge_sum;
}
int dis[N],used[N];
priority_queue<pair<int,int> >q;
void prim()
{
    memset(dis,inf,sizeof(dis));
    dis[1]=0;q.push(make_pair(0,1));
    while(q.size())
    {
        int x=q.top().second;q.pop();used[x]=1;
        for(int i=head[x];i!=0;i=nxt[i])
        {
            int y=to[i],z=w[i];
            if(dis[y]>z&&!used[y])
            {
                dis[y]=z;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}
int main()
{
    int n,m,ans=-inf;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    prim();
    for(int i=1;i<=n;i++)
        ans=max(ans,dis[i]);
    cout<<ans<<endl;
}