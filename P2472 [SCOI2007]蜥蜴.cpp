#include<bits/stdc++.H>
using namespace std;
const int maxn=1e3+5;
int n,m,d;
int a[25][25];
char b[25][25];
int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%1d",&a[i][j]);
    for(int i=1;i<=n;i++)
        scanf("%s",b[i]+1);
    return 0;
}