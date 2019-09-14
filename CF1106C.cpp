#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long LL;
LL a[N],sum,minx;
int main()
{
    int n;
    cin>>n;
    int l=1,r=n;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    while(l<r)
    {
        minx=min(a[l]+a[r],minx);
        sum+=(a[l]+a[r])*(a[l++]+a[r--]);
    }
    if(n%2)
    {
        sum-=minx*minx;
        minx+=a[l];
        sum+=minx*minx;
    }
    cout<<sum<<endl; 
    return 0;
}