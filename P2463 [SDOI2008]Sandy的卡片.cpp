#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,a[N][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=a[i][0];j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        a[i][0]--;
        if(a[i][0]==0) return puts("1"),0;
        for(int j=1;j<=a[i][0];j++)
            a[i][j]=a[i][j+1]-a[i][j];
    }
    int ans=0;
    for(int l=1;l<=a[1][0];l++)
    {
        int r=a[1][0];
        for(int i=2;i<=n;i++)
        {
            int maxx=0;
            for(int j=1;j<=a[i][0];j++)
                if(a[i][j]==a[1][l])
                {
                    int p=j,re=l;
                    while(a[i][p]==a[1][re]&&p<=a[i][0]&&re<=r)
                        re++,p++;
                    maxx=max(maxx,re-1);
                }
            r=min(r,maxx);
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans+1);
    return 0;
}