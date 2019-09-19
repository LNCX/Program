#include<bits/stdc++.h>
const int N=50010,mod=987654321;
using namespace std;
int n,m,c,a[N][15],e[N],dp[N][15],ans;
int main()
{
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1,opt,x,y;i<=m;i++)
    {
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==1)
            for(int j=1;j<=c;j++)
                {if(j!=y) a[x][j]=1;}
        else if(opt==2) a[x][y]=1;
        else
        {
            if(x>y)swap(x,y);
            e[y]=x;
        }
    }
    for(int p=1;p<=c;p++)
    {
        if(a[1][p]) continue;
        memset(dp,0,sizeof(dp));
        dp[1][p]=1;
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(a[i][j]) continue;
                if(e[i])
                {
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=mod;
                }
                else
                    for(int k=1;k<=c;k++)
                    {
                        if(j==k) continue;
                        dp[i][j]+=dp[i-1][k];
                        dp[i][j]%=mod;
                    }
            }
        }
        for(int i=1;i<=c;i++)
        {
            if(a[n][i]||i==p) continue;
            if(e[n]) (dp[n][i]+=dp[n-1][i])%=mod;
            else
                for(int j=1;j<=c;j++)
                {
                    if(i==j) continue;
                    (dp[n][i]+=dp[n-1][j])%=mod;
                }
        }
        for(int i=1;i<=c;i++)
            (ans+=dp[n][i])%=mod;
    }
    printf("%d\n",ans);
    return 0;
}