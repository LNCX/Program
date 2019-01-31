#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1000000007;
LL n,m,k,N;
LL a[40][40],b[40][40],tmp[40][40];
int used[40];
void mul(LL fo[][40],LL to[][40])
{
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            for(int k=0;k<=N;k++)
                tmp[i][j]=(fo[i][k]*to[k][j]+tmp[i][j])%mod;
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            to[i][j]=tmp[i][j];
}
int main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    N=(1<<m)-1;
    for(int i=0;i<=N;i++)
    {
        int cnt=0,x=i; 
        while(x!=0)
        {
            if(x&1==1) cnt++;
            x>>=1;
        }
        if(cnt<=k) 
        {
            used[i]=true;
            a[i>>1][i]=1;
            a[(i>>1)+(1<<(m-1))][i]=1;
        }
        b[i][i]=1; 
    }
    while(n!=1)
    {
        if(n%2==1) mul(a,b);
        mul(a,a);
        n>>=1;
    }
    mul(a,b);
    LL ans=0;
    for(int i=0;i<=N;i++)
        if(used[i])
            ans+=b[i][i],ans%=mod;
    printf("%d\n",ans);
    return 0;
}

