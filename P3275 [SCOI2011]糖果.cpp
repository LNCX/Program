#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=2e5+5;
int w[maxm],nxt[maxm],to[maxm],head[maxm],edge_sum;
void add(int u,int v,int c)
{
    nxt[++edge_sum]=head[u];
    to[edge_sum]=v;
    head[u]=edge_sum;
}//0一样多，1大于
queue<int>q;
int vis[maxn],dis[maxn],tot[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);
        if(x==1)
            add(a,b,0),add(b,a,0);
        else if(x==2)
        {
            if(a==b)
            {
                cout<<-1<<endl;
                return 0;
            }
            add(a,b,1);
        }
        else if(x==3) add(b,a,0);
        else if(x==4)
        {
            if(a==b)
            {
                cout<<-1<<endl;
                return 0;
            }
            add(b,a,1);
        }
        else if(x==5) add(a,b,0);
    }
    for(int i=1;i<=n;i++)
        add(0,i,1);
    vis[0]=1,q.push(0);
    while(!q.empty())
    {
        int u=q.front();q.pop();vis[u]=0;
        if(tot[u]==n-1){cout<<-1;return 0;}
        tot[u]++;
        for(int i=head[u];i!=0;i=nxt[i])
            if(dis[to[i]]<dis[u]+w[i])
            {
                dis[to[i]]=dis[u]+w[i];
                if(!vis[to[i]])vis[to[i]]=1,q.push(to[i]);
            }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=dis[i];
    cout<<ans<<endl;
}