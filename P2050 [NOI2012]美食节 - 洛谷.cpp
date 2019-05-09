#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+6,maxm=4e7+6,inf=0x3f3f3f3f;
int n,m,s,t,ans,d[maxn],pre[maxn],now[maxn],num,p[maxn];
int head[maxn],e[maxm],Leng[maxm],Cost[maxm],nxt[maxm],tot=1;
bitset<maxn> v;
int a[46][106];
void add(int x,int y,int z,int w)
{
    e[++tot]=y;
    Leng[tot]=z;
    Cost[tot]=w;
    nxt[tot]=head[x];
    head[x]=tot;
}
bool spfa()
{
    v.reset();
    memset(d,0x3f,sizeof(d));
    queue<int> q;
    q.push(s);
    v[s]=1;
    d[s]=0;
    now[s]=inf;
    while (q.size())
    {
        int x=q.front();
        q.pop();
        v[x]=0;
        for (int i=head[x]; i; i=nxt[i])
        {
            int y=e[i],z=Leng[i],w=Cost[i];
            if(!z || d[y]<=d[x]+w)
                continue;
            d[y]=d[x]+w;
            now[y]=min(now[x],z);
            pre[y]=i;
            if(!v[y])
            {
                q.push(y);
                v[y]=1;
            }
        }
    }
    return d[t] != inf;
}
inline void upd()
{
    ans += d[t] * now[t];
    int x=t;
    while (x != s)
    {
        int i=pre[x];
        Leng[i]-=now[t];
        Leng[i^1]+=now[t];
        x=e[i^1];
    }
    x=e[pre[t] ^ 1];
    p[++num]=p[x];
    add(num,t,1,0);
    add(t,num,0,0);
    for(int i=head[x];i!=0;i=nxt[i])
    {
        int y=e[i],w=Cost[i ^ 1];
        if(y == t)
            continue;
        w += a[y][p[x]];
        add(y,num,1,w);
        add(num,y,0,-w);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add(0,i,x,0);
        add(i,0,0,0);
    }
    num=t=n+m+1;
    for(int i=1;i<= n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            a[i][j]=x;
            add(i,n+j,1,x);
            add(n+j,i,0,-x);
        }
    for(int i=1; i <= m; i++)
    {
        add(n+i,t,1,0);
        add(t,n+i,0,0);
        p[n+i]=i;
    }
    while(spfa())
        upd();
    cout<<ans<<endl;
    return 0;
}