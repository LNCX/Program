#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N][2],f[N][3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int j=0;j<2;j++)
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        f[i][0]=max(f[i-1][1],f[i-1][2])+a[i][0];
        f[i][1]=max(f[i-1][0],f[i-1][2])+a[i][1];
        f[i][2]=max(max(f[i-1][0],f[i-1][1]),f[i-1][2]);
    }
    cout<<max(max(f[n][0],f[n][1]),f[n][2]);
}