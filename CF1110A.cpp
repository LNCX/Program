#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5,mod=10;
LL b,k,a[N],n;
int main()
{
    scanf("%lld%lld",&b,&k);
    for(int i=k-1;i>=0;i--)
        scanf("%lld",&a[i]);
    n+=a[0];n%=mod;
    int mid=b;
    for(int i=1;i<=k-1;i++)
    {
        n+=a[i]*mid;
        n%=mod;
        mid*=b;
        mid%=mod;
    }
    //cout<<n<<endl;
    if(n%2) puts("odd");
    else puts("even");
    return 0;
}