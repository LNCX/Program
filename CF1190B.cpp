#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,cnt,sum,a[N];
void print(long long x){x?puts("sjfnb"):puts("cslnb");exit(0);}
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        sum+=*(a+i);
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++)
        if(a[i]==a[i-1])
            cnt++;
    if(cnt>1) print(0);
    for(long long i=2;i<=n&&cnt==1;i++)if(a[i]==a[i-1])
        {
            if(i!=2&&a[i-2]==a[i-1]-1) print(0);
            else if(a[i]==0) print(0);
        }
    sum-=n*(n-1)/2;
    if(sum<=0) print(0);
    if(sum&1) print(1);
    else print(0);
}
