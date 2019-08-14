#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,f[N][N],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j],f[i-1][j-1]+(x==j)),ans=max(ans,f[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}