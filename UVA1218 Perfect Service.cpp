#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int maxm=N<<1;
int nxt[N],v[N],head[N],sum;
void add(int x,int y)
{
    nxt[sum]=head[x];
    v[sum]=y;
    head[x]=sum++;
}
int dp[N][3];
void dfs(int x, int f)
{
    dp[x][0]=1,dp[x][1]=0,dp[x][2]=N;
    for (int i=head[x];~i;i=nxt[i])
        if (v[i]!=f)
        {
            dfs(v[i],x);
            dp[x][0]+=min(dp[v[i]][0],dp[v[i]][1]);
            dp[x][1]+=dp[v[i]][2];
        }
    for (int i=head[x];~i;i=nxt[i])
        if(v[i]!=f)
            dp[x][2]=min(dp[x][2], dp[x][1]+dp[v[i]][0]-dp[v[i]][2]);
    return;
}
int main()
{
    while(true)
    {
        int n,m;
        sum=0;
        memset(head,-1,sizeof(head)); 
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y),add(y,x);
        }
        dfs(1,0);
        printf("%d\n",min(dp[1][0],dp[1][2]));
        scanf("%d",&m);
        if(m==-1) break;
    }
    return 0;
}
