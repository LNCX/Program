#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
long long ans,a[N];
int main()
{
    int n,x=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        x++;
        scanf("%lld",&a[x]);
        while(x>=2&&a[x-1]<=min(a[x],a[x-2]))
        {
            ans+=min(a[x],a[x-2]);
            a[x-1]=a[x];
            x--;
        }
    }
    for(int i=1;i<x;i++)
        ans+=min(a[i-1],a[i+1]);
    cout<<ans<<endl;
}