#include<bits/stdc++.h>
using namespace std;
const int N=255;
char s[N][N];
int f[N][N],n,cnt[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        f[i][0]=(s[i][0]=='1');
        f[0][i]=(s[0][i]=='1');
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(s[i][j]=='1')
        {
            f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
            cnt[f[i][j]]++;
        }
    for(int i=n;i>1;i--) cnt[i-1]+=cnt[i];
    for(int i=2;i<=n;i++) cnt[i]?printf("%d %d\n",i,cnt[i]):0;
    return 0;
}