#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int a[maxn];
int main()
{
    int n,z;
    scanf("%d%d",&n,&z);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int k=1;
    ll ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]-a[k]>=z) k++;
    cout<<min(n>>1,k-1)<<endl;
    return 0;
}