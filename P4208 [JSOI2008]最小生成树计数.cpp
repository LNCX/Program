#include<bits/stdc++.h>
using namespace std;
const int N=105,maxm=1e3+5,mod=31011;
int n,m,cnt,sum,l[maxm],r[maxm],c[maxm],fa[N];
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &b) const
    {
        return w<b.w;
    }
}e[maxm];
int find(int x){return fa[x]==x?x:find(fa[x]);}
void dfs(int now,int x,int num)
{
    if(now>r[x])
    {
        sum+=(num==c[x]);
        return;
    }
    int fu=find(e[now].u),fv=find(e[now].v);
    if(fu!=fv)
    {
        fa[fu]=fv;
        dfs(now+1,x,num+1);
        fa[fu]=fu,fa[fv]=fv;
    }
    dfs(now+1,x,num);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) 
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int tot=0;
    for(int i=1;i<=m;i++)
    {
        if(e[i].w!=e[i-1].w) 
        {
            r[cnt]=i-1;
            l[++cnt]=i;
        }
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu!=fv) 
        {
            c[cnt]++;
            fa[fu]=fv;
            tot++;
        }
    }
    r[cnt]=m;
    if(tot!=n-1)
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int ans=1;
    for(int i=1;i<=cnt;i++)
    {
        sum=0;
        dfs(l[i],i,0);
        ans=ans*sum%mod;
        for(int j=l[i];j<=r[i];j++)
            fa[find(e[j].u)]=find(e[j].v);
    }
    printf("%d\n",ans);
    return 0;
}