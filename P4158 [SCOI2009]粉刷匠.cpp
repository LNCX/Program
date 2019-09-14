#include<bits/stdc++.h>
using namespace std;
const int N=55;
char s[N][N];
int f[N][N][2505][2],n,m,t;
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)    
        for(int j=1;j<=m;j++)
            for(int k=1;k<=t;k++)
            {
                if(j==1)
                {
                    f[i][j][k][0]=max(f[i-1][m][k-1][1],f[i-1][m][k-1][0]);
                    f[i][j][k][1]=max(f[i-1][m][k-1][1],f[i-1][m][k-1][0])+1;
                }
                else
                {
                    if(s[i][j]==s[i][j-1])
                    {
                        f[i][j][k][0]=f[i][j-1][k][0];
                        f[i][j][k][1]=f[i][j-1][k][1]+1;  
                    }
                    else
                    {
                        f[i][j][k][0]=max(f[i][j-1][k-1][0],f[i][j-1][k][1]);
                        f[i][j][k][1]=max(f[i][j-1][k][0],f[i][j-1][k-1][1])+1;
                    }
                }
            }
    printf("%d\n",max(f[n][m][t][0],f[n][m][t][1]));
    return 0;
}