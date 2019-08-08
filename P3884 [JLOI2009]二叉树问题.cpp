#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,s,t,tot,ans1,ans2,f[N];
int a[N],head[N],wid[N],dep[N];
struct Edge
{
    int v,nxt;
}e[N];
void add(int u,int v)
{
    e[++tot].nxt=head[u];
    e[tot].v=v;
    head[u]=tot;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u]=fa;
    wid[dep[u]]++;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
    }
}
int LCA(int x,int y)
{
    int ans=0;
    if(dep[x]>dep[y])
        while(dep[x]!=dep[y])
        {
            x=f[x];
            ans+=2;
        }
    if(dep[x]<dep[y])
        while(dep[x]!=dep[y])
        {
            y=f[y];
            ans+=1;
        }
    while(x!=y)
    {
        x=f[x],y=f[y];
        ans+=3;
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    scanf("%d%d",&s,&t);
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        ans1=max(dep[i],ans1);
        ans2=max(wid[i],ans2);
    }
    printf("%d\n%d\n",ans1,ans2);
    cout<<LCA(s,t)<<endl;
    return 0;
}