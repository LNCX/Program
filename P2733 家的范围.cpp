#include<bits/stdc++.h>
using namespace std;
const int N=255;
char s[N][N];
int f[N][N],num[N*N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++) f[i][1]=(s[i][1]=='1');
    for(int i=1;i<=n;i++) f[1][i]=(s[i][1]=='1');
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++) if(s[i][j])
        {
            f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
            num[f[i][j]]++;
        }
    for(int i=n;i>0;i--) num[i-1]+=num[i];
    for(int i=2;i<=n;i++)   printf("%d %d\n",i,num[i]);
    return 0;
}