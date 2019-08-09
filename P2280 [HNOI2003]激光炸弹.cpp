#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int f[N][N],ans;
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        f[x+1][y+1]=z;
    }
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
     for(int i=0;i<=5000-r;i++)
            for(int j=0;j<=5000-r;j++)
                ans=max(ans,f[i+r][j+r]-f[i+r][j]-f[i][j+r]+f[i][j]);
    cout<<ans<<endl;
    return 0;
}