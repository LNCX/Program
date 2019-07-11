#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1005;
int a[maxn][maxn];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%1d",&a[i][j]);
    while(q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    }
    return 0;
}