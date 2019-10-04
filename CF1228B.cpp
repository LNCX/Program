#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e3+5,mod=1e9+7;
int a[N][N],n,m,cnt;
ll power(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=a*ans%mod;
        b>>=1;a=a*a%mod;
    }
    return ans%mod;
}
void kill()
{
    puts("0");
    exit(0);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++)
            a[i][j]=1;
        if(a[i][x+1]==1) kill();
        a[i][x+1]=-1;
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++)
        {
            if(a[j][i]==-1) kill();
            a[j][i]=1;
        }
        if(a[x+1][i]==1) kill();
        a[x+1][i]=-1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==0)
               cnt++;
    cout<<power(2,(ll)cnt)<<endl;
    return 0;
}