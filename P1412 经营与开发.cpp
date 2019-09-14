#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
double f[N];
int a[N],b[N],n,k,c,w;
int main()
{
    scanf("%d%d%d%d",&n,&k,&c,&w);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=n;i>0;i--)
    {
        if(a[i]==1) f[i]=max(f[i+1],f[i+1]*(1-0.01*k)+b[i]);
        else f[i]=max(f[i+1],f[i+1]*(1+0.01*c)-b[i]);
    }  
    printf("%.2lf\n",f[1]*w);
    return 0;
}