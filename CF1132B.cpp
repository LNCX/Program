#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
ll a[N],b[N],tot;
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n,greater<int>{});
    for(int i=1;i<=n;i++)
        tot+=a[i];
    cin>>m;
    while(m--)
    {
        ll q;
        scanf("%lld",&q);
        printf("%lld\n",tot-a[q]);
    }
    return 0;
}