#include<bits/stdc++.h>
using namespace std;
long long l=1,r,f[20],a[10],b[10],ten[20]={1};
void pre()
{
    for(int i=1;i<=14;i++)
    {
        f[i]=f[i-1]*10+ten[i-1];
        ten[i]=10*ten[i-1];
    }
}
void solve(long long x,long long *ans)
{
    long long len=0,num[20]={0};
    memset(ans,0,sizeof(ans));
    while(x)
    {
        len++;
        num[len]=x%10;
        x/=10;
    }
    for(int i=len;i>=1;i--)
    {
        for(int j=0;j<=9;j++)
            ans[j]+=f[i-1]*num[i];
        for(int j=0;j<num[i];j++)
            ans[j]+=ten[i-1];
        long long mid=0;
        for(int j=i-1;j>=1;j--)
            mid=mid*10+num[j];
        ans[num[i]]+=mid+1;
        ans[0]-=ten[i-1];
    }
}
int main()
{
    scanf("%lld",&r);
    pre();
    solve(l-1,a),solve(r,b);
    for(int i=0;i<=9;i++)
        printf("%lld\n",b[i]-a[i]);
}
