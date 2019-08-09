#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
const int maxm=1e6+5;
int ans[2],size[N],maxx[2],head[maxm],to[N],nxt[maxm],edge_sum;
void add(int u,int v)
{
    nxt[++edge_sum]=head[u];
    to[edge_sum]=v;
    head[u]=edge_sum;
}
int dfn[N],st[N],co[N],low[N],top,dfstime,cnt;
void tarjan(int u)
{
    dfn[u]=low[u]=++dfstime;
    st[++top]=u;
    for(int i=head[u];i!=0;i=nxt[i])
    {
        int v=to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!co[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int minx=u;
        co[u]=++cnt;
        size[cnt]++;
        while(st[top]!=u)
        {
            co[st[top]]=cnt;
            minx=min(st[top],minx);
            size[cnt]++;
            top--;
        }
        top--;
        if(size[cnt]>maxx[0])
        {
            maxx[0]=size[cnt];
            ans[0]=cnt,ans[1]=size[cnt];
        }
        if(size[cnt]==maxx[0]&&minx<maxx[1])
        {
            maxx[1]=minx;
            ans[0]=cnt,ans[1]=size[cnt];
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        if(t==1) add(a,b);
        else add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    printf("%d\n",ans[1]);
    for(int i=1;i<=n;i++)
        if(co[i]==ans[0])
            printf("%d ",i);
    cout<<endl;
}
