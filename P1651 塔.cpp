#include<bits/stdc++.h>
using namespace std;
const int N=55,M=5e5,inf=-0x3f3f3f3f;
int a[N],f[2][M*4+5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(f,inf,sizeof(f));
    f[0][M<<1]=0; 
    for(int i=1;i<=n;i++)
        for(int j=M;j<=3*M;j++)
        {
            int k=i%2;
            f[k][j]=max(f[k^1][j-a[i]]+a[i],max(f[k^1][j+a[i]],f[k^1][j]));
        }
    f[n%2][M<<1]<=0?puts("-1"):printf("%d\n",f[n%2][M<<1]);
    return 0;
}