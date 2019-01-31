#include<bits/stdc++.h>
using namespace std;
const int maxn=1505;
const int inf=0x3f3f3f3f;
int n,m,ans,lena,lenb;
int p[5],dis[maxn][5],l1,l2;
int head[maxn*maxn],nxt[maxn*maxn],w[maxn*maxn],to[maxn*maxn],edge_sum;
void add(int u,int v)
{
    nxt[++edge_sum]=head[u];
    to[edge_sum]=v;
    w[edge_sum]=1;
    head[u]=edge_sum;
}
queue<int>q;
int used[maxn];
void SPFA(int s,int n)
{
    memset(used,0,sizeof used);
    while(q.size()) q.pop();
    dis[s][n]=0,used[s]=1;
    q.push(s);
    while(q.size())
    {
        int x=q.front();q.pop(),used[x]=0;
        for(int i=head[x];i!=0;i=nxt[i])
        {
            int y=to[i],z=w[i];
            if(dis[x][n]+z<dis[y][n])
            {
                dis[y][n]=dis[x][n]+z;
                if(!used[y]) q.push(y),used[y]=1;
            }
        }
    }
}
bool check(int x)
{
    if(dis[x][1]+dis[x][2]!=lena||dis[x][3]+dis[x][4]!=lenb)
        return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v; 
        scanf("%d%d",&u,&v); 
        add(u,v),add(v,u); 
    } 
    scanf("%d%d%d",&p[1],&p[ 2],&l1);
    scanf("%d%d%d",&p[3],&p[4],&l2);
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=4;i++)
    	SPFA(p[i],i);
    lena=dis[p[2]][1],lenb=dis[p[4]][3];
    if(lena>l1||lenb>l2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) if(check(i))
    	for(int j=1;j<=n;j++) if(check(j))
    		ans=max(ans,abs(dis[i][1]-dis[j][1]));
    cout<<m-(lena+lenb-ans)<<endl;
    return 0;
}