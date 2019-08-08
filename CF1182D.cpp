#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct edge
{
    int nxt,to;
}e[N<<1];
int head[N],tot,dis[N];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
class find_rt
{
    public:
        int find()
        {
            int x=dfs(1,0),y=dfs(x,0);
            return get_rt(x,y);
        }
    private:
        int pre[N],vis[N];
        int get_rt(int s,int t)
        {
            memset(pre,0,sizeof(pre));
            memset(vis,0,sizeof(vis));
            bfs(s,t);
            int cnt=0;
            for(int u=pre[t];u!=0;u=pre[u])
                cnt++;
            if(cnt%2) return -1;
            int cnt1=0;
            for(int u=pre[t];u!=0;u=pre[u])
            {  
                cnt1++;
                if(cnt1*2==cnt)
                    return u;
            }
        }
        int dfs(int u,int fa)
        {
            int maxx=u;
            for(int i=head[u];i!=0;i=e[i].nxt)
            {
                int v=e[i].to;
                if(v==fa) continue;
                dis[v]=dis[u]+1;
                int x=dfs(v,u);
                if(dis[maxx]<dis[x]) maxx=x;
            }
            return maxx;
        }
        void bfs(int s,int t)
        {
            queue<int>q;
            q.push(s),vis[s]=1;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int i=head[u];i!=0;i=e[i].nxt)
                {
                    int v=e[i].to;
                    if(vis[v]) continue;
                    pre[v]=u,vis[v]=1;
                    if(v==t) return;
                    q.push(v);
                }
            }
        }
}rt;
class size
{
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    int mid=rt.find();

    return 0;
}