#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
char s[maxn][maxn];
int c[maxn][maxn];
int main()
{
    int n,m;
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&c[i][j]);

    return 0;
}