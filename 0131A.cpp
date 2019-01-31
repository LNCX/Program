#include<bits/stdc++.h>
using namespace std;
char ans[55][55];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[i][j]='.';
    for(int i=1;i<=n;i++) if(i%2)
        for(int j=1;j<=m;j++)
            ans[i][j]='#';
    for(int i=1;i<=n;i++) if(!(i%2))
    {
        if((i/2)%2) ans[i][m]='#';
        else ans[i][1]='#';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%c",ans[i][j]);
        puts("");
    }
    return 0;
}