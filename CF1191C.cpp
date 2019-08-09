#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N],n,m,k;
int main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%lld",&a[i]);
    int ans=0;
    for(int i=1;i<=m;ans++)
    {
        int d=i-1;
        ll now=(a[i]-d-1)/k;
        i++;
        while((a[i]-d-1)/k==now)
            i++;
    }
    cout<<ans<<endl;
    return 0;
}
