#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],f[N][20],Log[N]={-1};
//f[i][j]=min{i,(2^j)+i-1}=min{f[i][j-1],f[i+2^(j-1)][j-1]}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(f,0x3f3f3f3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[i][0]=a[i];
        Log[i]=Log[i>>1]+1;
    }
    for(int j=1;j<20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int k=Log[r-l+1];
        printf("%d ",min(f[l][k],f[r-(1<<k)+1][k]));
    }
    return 0;
}