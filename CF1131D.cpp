#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
char s[N][N];
int w[N][N],dis[N],tot[N],vis[N];
int head[N],cnt;
queue<int>q;
struct Edge
{
    int nxt,to,w;
}e[N*N];
void add(int u,int v,int w)
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].w=w;
    head[u]=cnt;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='>')
                add(j+n,i,1);
            else if(s[i][j+n]=='<')
                add(i,j+n,1);
            else add(i,j+n,0),add(j+n,i,0);
        }
    for(int i=n;i>=1;i--)
        add(0,i,1);
    vis[0]=1;q.push(0);
    while(!q.empty())
    {
        int u=q.front();q.pop();vis[u]=0;
        if(tot[u]==m+n-1)
        {
            puts("No");
            return 0;
        }
        tot[u]++;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v]) vis[v]=1,q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    puts("");
    for(int i=n+1;i<=n+m;i++)
        printf("%d ",dis[i]);
    return 0;
}