#include<bits/stdc++.h>
using namespace std;
const int N=505;
long double f[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++) f[n][i]=1;
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>=0;j--)
            for(int k=1;(k>>1)<=n;k<<=1)
                f[i][j]=max(f[i][j],(f[min(i+k,n)][j]+f[min(i+k,n)][j+1]+(2*k-1)*f[i][j+1])/(2*k+1));           
    printf("%.6Lf\n",f[0][0]);
    return 0;
}