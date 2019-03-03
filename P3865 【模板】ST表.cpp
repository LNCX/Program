#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],f[maxn][20],Log[maxn]={-1};
//f[i][j]=max{i,(2^j)+i-1}=max{f[i][j-1],f[i+2^(j-1)][j-1]}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[i][0]=a[i];
        Log[i]=Log[i>>1]+1;
    }
    for(int j=1;j<20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int k=Log[r-l+1];
        printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
    }
    return 0;
}