#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll f[N][205],sum[N],q[N];
void print(int n,int m)
{
    for(int i=n-1;i>=m;i--)
        if(f[n][m]==f[i][m-1]+sum[i]*(sum[n]-sum[i]))
        {
            printf("%d ",i);
            n=i;m--;
            if(m==0) break;
        }
}
inline double calc(int x,int y,int k)
{
    if(sum[x]==sum[y]) return 1e18;
    return (double)(sum[x]*sum[x]-f[x][k-1]-sum[y]*sum[y]+f[y][k-1])/(sum[x]-sum[y]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        sum[i]+=sum[i-1]+x;
    }
    for(int k=1;k<=m;k++)
    {
        int l=1,r=0;
        q[++r]=k;
        for(int i=k+1;i<=n;i++)
        {
            while(l<r&&calc(q[l],q[l+1],k)<sum[i]) l++;
            f[i][k]=f[q[l]][k-1]+sum[q[l]]*(sum[i]-sum[q[l]]);
            while(l<r&&calc(q[r-1],q[r],k)>calc(q[r],i,k)) r--;
            q[++r]=i;
        }
    }
    cout<<f[n][m]<<endl;
    print(n,m);
    puts("");
    return 0;
}