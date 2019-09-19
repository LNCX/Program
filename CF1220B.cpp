#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000][2000],n,c;
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
	printf("%lld\n",(c=sqrt(a[1][2]*a[1][3]/a[3][2])));
	for(int i=1;i<=n-1;i++)
        printf("%lld ",(c=a[i][i+1]/c));
}