#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        double ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            ans+=(double)n/i;
        printf("%lf\n",ans);
    }
    return 0;
}