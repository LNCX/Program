#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int q,n,k,sum[N][3];
char s[N],d[]={'R','G','B'};
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        int ans=0x7fffffff;
        scanf("%d%d%s",&n,&k,s+1);
        for(int i=1;i<=n;i++)
            for(int j=0;j<3;j++)
                sum[i][j]=sum[i-1][j]+(s[i]!=d[(i+j)%3]);
        for(int i=1;i+k-1<=n;i++)
            for(int j=0;j<3;j++)
                ans=min(sum[i+k-1][j]-sum[i-1][j],ans);
        printf("%d\n",ans);
    }
    return 0;
}