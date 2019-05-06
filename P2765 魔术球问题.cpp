#include<bits/stdc++.h>
using namespace std;
int sqr(int a){return a*a;}
int a[100][100];
int main()
{
    int n;
    scanf("%d",&n);
    int m=(n*(n+2)+(n&1)-2)/2;
    printf("%d\n",m);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            int x=a[j][a[j][0]];
            if(!x||sqr(int(sqrt(x+i)))==x+i)
            {
                a[j][++a[j][0]]=i;
                break;
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i][0];j++)
            printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}