#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,t=0;
    while(scanf("%d%d",&n,&d)&&d)
    {
        double ans=0;
        while (n--)
        {
            int p,l,v;
            scanf("%d%d%d",&p,&l,&v);
            d-=l,ans+=2.0*l/v;
        }
        printf("Case %d: %.3lf\n\n",++t,ans+d);
    }
    return 0;
}