#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
char a[N],b[N];
int f[N][N],n,m,k;
int main()
{
    scanf("%s%s%d",a+1,b+1,&k);
    n=strlen(a+1),m=strlen(b+1);
    for(int i=1;i<=n;i++) f[i][0]=f[i-1][0]+k;
    for(int i=1;i<=m;i++) f[0][i]=f[0][i-1]+k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=min(f[i-1][j]+k,min(f[i][j-1]+k,f[i-1][j-1]+abs((int)a[i]-(int)b[j])));
    printf("%d\n",f[n][m]);
    return 0;
}