#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
LL f[N][35],cnt[N][35];//f[i][j]means destroy bases end with i,lenth 2^j
int main()
{
    LL n,k,A,B;
    scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x][0]++;
    }
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;j<=n;j++)
        {
            int l=i-(1<<(j-1));
            if(l>=1)
                cnt[i][j]=cnt[i][j-1]+cnt[l][j-1];
            else cnt[i][j]=cnt[i][j-1];
//cnt[i][j]=cnt[i][j-1]+cnt[i-1<<(j-1)][j-1]
        }
    for(int i=1;i<=(1<<n);i++)
    {
        if(cnt[i][0]) f[i][0]=cnt[i][0]*B;
        else f[i][0]=A;
    }
    for(int i=1;i<=(1<<n);i++)
        for(int j=1;(1<<j)<=i;j++)
        {
            int l=i-(1<<(j-1));
            if(!cnt[i][j]) f[i][j]=A;
            else 
            {
                //f[i][j]=min(2^j*Na*B,f[i][j-1]+f[i-1<<(j-1)][j-1])
                if(l>=1) f[i][j]=min((1<<j)*cnt[i][j]*B,f[i][j-1]+f[l][j-1]);
                else f[i][j]=f[i][j-1];
            }
        }
    cout<<f[(1<<n)][n]<<endl;
    return 0;
}