#include<bits/stdc++.h>
using namespace std;
int a[105];
double f[105][2];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[1][0]=100;f[1][1]=a[1];
    for(int i=2;i<=n;i++)
    {
        f[i][0]=max(f[i-1][0],f[i-1][1]/a[i]*100);
        f[i][1]=max(f[i-1][1],f[i-1][0]/100*a[i]);
    }
    printf("%.2lf",max(f[n][0],f[n][1]/a[n]*100));
}