#include<bits/stdc++.h>
using namespace std;
const int N=105;
double f[N][N];
int main()
{
    int q,n;
    scanf("%d%d",&q,&n);
    if(q==1)
    {
        double ans=0;
        for(int i=2;i<=n;i++)
            ans+=(double)2/i;
        printf("%.6f",ans);
    }
    else
    {
        for(int i=1;i<=n;i++) f[i][0]=1;
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
            {
                for(int k=1;k<i;k++)
                    f[i][j]+=f[k][j-1]+f[i-k][j-1]-f[k][j-1]*f[i-k][j-1];
                f[i][j]/=(i-1);
            }
        double ans=0;
        for(int i=1;i<n;i++) ans+=f[n][i];
        printf("%.6lf\n",ans);
    }
	return 0;
}     