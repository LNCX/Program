#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int a[20][20]={0};
int ch[20]={0},gs=1;
int lc[20]={0},hc[20][20]={0};
int f[20][20];
void mems()
{
    for(int i=1;i<=m;i++)
    {
        lc[i]=0;
        for(int j=1;j<r;j++)
            lc[i]+=abs(a[ch[j]][i]-a[ch[j+1]][i]);
    }
    for(int i=2;i<=m;i++)
        for(int j=1;j<i;j++)
        {
            hc[i][j]=0;
            for(int k=1;k<=r;k++)
                hc[i][j]+=abs(a[ch[k]][i]-a[ch[k]][j]);
    	}
}
int minn=2e9;
int cmin;
void dp()
{
    for(int i=1;i<=m;i++)
    {
        cmin=min(i,c);
        for(int j=1;j<=cmin;j++)
        {
            if(j==1)
                f[i][j]=lc[i];
            else
            if(i==j)
                f[i][j]=f[i-1][j-1]+lc[i]+hc[i][j-1];
            else
            {
                f[i][j]=2e8;
                for(int k=j-1;k<i;k++)
                    f[i][j]=min(f[i][j],f[k][j-1]+lc[i]+hc[i][k]);
            }
            if(j==c)minn=min(minn,f[i][c]);
        }
    }
}
void dfs(int node)
{
    if(node>n)
    {
        mems();
        dp();
        return;
    }
    if(r-gs+1==n-node+1)
    {
        ch[gs++]=node;
        dfs(node+1);
        ch[gs--]=0;
        return;
    }
    dfs(node+1);
    if(gs<=r)
    {
        ch[gs++]=node;
        dfs(node+1);
        ch[gs--]=0;
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    printf("%d",minn);
}
