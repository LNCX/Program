#include<bits/stdc++.h>
using namespace std;
int a[40][40];
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                scanf("%d",&a[i][j]);
        int ans=a[1][2];
        for(int i=3;i<=n;i++)
        {
            int minx=0x7fffffff;
            for(int j=2;j<i;j++)
                minx=min(minx,a[1][i]-(a[1][j]+a[1][i]-a[j][i])/2);
            ans+=minx;
        }
        printf("%d\n",ans);
    }
    return 0;
}