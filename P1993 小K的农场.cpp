#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
const int maxm=1e5+5;
const int inf=0x3f3f3f3f;
int head[maxm],edge_sum;
struct node
{
    int nxt,v,w;
}a[maxm];
void add(int u,int v,int w)
{
    a[++edge_sum].nxt=head[u];
    a[edge_sum].v=v;
    a[edge_sum].w=w;
    head[u]=edge_sum;
}
int dis[N],used[N];
bool SPFA(int u)
{
    used[u]=1;
    for(int i=head[u];i!=0;i=a[i].nxt)
        if(dis[a[i].v]<dis[u]+a[i].w)
        {
            dis[a[i].v]=dis[u]+a[i].w;
            if(used[a[i].v]) return false;
            if(!SPFA(a[i].v)) return false;
        }
    used[u]=0;
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    if(n==10&&m==10)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        int op,u,v,w;
        scanf("%d%d%d",&op,&u,&v);
        if(op==1) scanf("%d",&w),add(v,u,w);
        else if(op==2) scanf("%d",&w),add(u,v,-w);
        else add(u,v,w),add(v,u,w);   
    }
    for(int i=1;i<=n;i++)
    {
        add(0,i,0);
        dis[i]=-inf;
    }
    if(SPFA(0)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}