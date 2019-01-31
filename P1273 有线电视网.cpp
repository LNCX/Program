#include<bits/stdc++.h>
using namespace std;
int n,m;
int head[3010],k;
int val[3010];
int f[3010][3010];
struct node
{
    int to,next,w;
}edge[10000010];
void adde(int u,int v,int w)
{
    edge[++k].to=v; edge[k].next=head[u];
    edge[k].w=w; head[u]=k;
}
int dfs(int u)
{
    if(u>n-m)
    {
        f[u][1]=val[u];
        return 1;
    } 
    int sum=0,t;
    for(int k=head[u];k;k=edge[k].next)
    {
        int v=edge[k].to;
        t=dfs(v); 
		sum+=t;
        for(int j=sum;j>0;j--)
            for(int i=1;i<=t;i++) 
                if(j-i>=0) 
					f[u][j]=max(f[u][j],f[u][j-i]+f[v][i]-edge[k].w);
    }
    return sum;
}
int main()
{
    memset(f,~0x3f,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int u=1;u<=n-m;u++)
    {
        int size,v,w;
        scanf("%d",&size);
        for(int j=1;j<=size;j++)
        {
            scanf("%d%d",&v,&w);
            adde(u,v,w);
        }
    }
    for(int i=n-m+1;i<=n;i++) 
		scanf("%d",&val[i]);
    for(int i=1;i<=n;i++) 
		f[i][0]=0;
    dfs(1);
    for(int i=m;i>=1;i--)
        if(f[1][i]>=0)
        {
            printf("%d",i);
            break;
        }
    return 0;
}
