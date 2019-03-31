#include<bits/stdc++.h>
using namespace std;
const int mod=1e8;
int f[105][105][15][2];
int main()
{
    int n,m,k[2];
    scanf("%d%d%d%d",&n,&m,&k[0],&k[1]);
    f[1][0][1][0]=f[0][1][1][1]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            for(int s=1;s<=min(k[0],n)&&i;s++)
            {
                if(s==1)
                    for(int s1=1;s1<=min(j,k[1]);s1++)
                        (f[i][j][s][0]+=f[i-1][j][s1][1])%=mod;   
                else (f[i][j][s][0]+=f[i-1][j][s-1][0])%=mod;
            }
            for(int s=1;s<=min(k[1],m)&&j;s++)
            {
                if(s==1)
                    for(int s1=1;s1<=min(i,k[0]);s1++)
                        (f[i][j][s][1]+=f[i][j-1][s1][0])%=mod;
                else (f[i][j][s][1]+=f[i][j-1][s-1][1])%=mod;
            }
        }
    int ans=0;
    for(int s=1;s<=k[0];s++)
        (ans+=f[n][m][s][0])%=mod;
    for(int s=1;s<=k[1];s++)
        (ans+=f[n][m][s][1])%=mod;
    cout<<ans<<endl;
    return 0;
}