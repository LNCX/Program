#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>G[N],clr;
int dep[N],dp[N],f[N][18];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<18;i++)
        f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<G[u].size();i++)
    {
		int v=G[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
int LCA(int a,int b)
{
	if(dep[a]>dep[b])
        swap(a,b);
	if(dep[a]<dep[b])
    {
		int del=dep[b]-dep[a];
		for(int i=0;i<18;i++)
			if(del&(1<<i))
                b=f[b][i];
	}
	if(a!=b)
    {
		for(int i=17;i>=0;i--)
			if(f[a][i]!=f[b][i])
				a=f[a][i],b=f[b][i];
		a=f[a][0],b=f[b][0];
	}
	return a;
}
void bfs()
{
	queue<int>q;
	for(int i=0;i<clr.size();i++)
    {
		q.push(clr[i]);
        dp[clr[i]]=0;
	}
	while(!q.empty())
    {
		int u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++)
        {
			int v=G[u][i];
			if(dp[v]>dp[u]+1)
            {
				dp[v]=dp[u]+1;
				q.push(v);
			}
		}
	}
	clr.clear();
}
int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=n;i++)
        dp[i]=~0u>>2;
    clr.push_back(1);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    bfs();
    int block=sqrt(m*1.0)+1;
    for(int i=0;i<m;i++)
    {
        int op,u;
        scanf("%d%d",&op,&u);
        if(op==1)
        {
            clr.push_back(u);
            if(clr.size()==block)
                bfs();
        }
        else
        {
            int ans=dp[u];
            for(int i=0;i<clr.size();i++)
            {
                int v=clr[i];
                ans=min(ans,dep[u]+dep[v]-2*dep[LCA(u,v)]);
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}
