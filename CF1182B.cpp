#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
char s[maxn][maxn];
int cnt,ans;
bool flag;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='*')
                cnt++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='*'&&s[i+1][j]=='*'&&s[i-1][j]=='*'&&s[i][j+1]=='*'&&s[i][j-1]=='*')
            {
                ans++;
                for(int k=i+1;;k++)if(s[k][j]=='*')ans++;else break;
                for(int k=i-1;;k--)if(s[k][j]=='*')ans++;else break;
                for(int k=j+1;;k++)if(s[i][k]=='*')ans++;else break;
                for(int k=j-1;;k--)if(s[i][k]=='*')ans++;else break;
                if(ans!=cnt)
                {
                    puts("no");
                    return 0;
                }
                else
                {
                    flag=true;
                    break;
                }
            }
        }
    if(flag) puts("yes");
    else puts("no");
    return 0;
}