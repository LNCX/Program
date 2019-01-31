#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL phi[50005]={0,1};
void phi_make(int n)
{
    for(int i=2;i<=n;i++) if(!phi[i])
        for(int j=i;j<=n;j+=i)
        {
            if(!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}
int main()
{
    int n;
    phi_make(50005);
    while(scanf("%d",&n)&&n!=0)
    {
        LL ans=0;
        for(int i=2;i<=n;i++)
            ans+=phi[i];
        printf("%lld\n",2*ans+1);
    }
    return 0;
}