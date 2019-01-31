#include <bits/stdc++.h>
using namespace std;
int n,d[2505];
int main()
{
    int n;
    scanf("%d%d",&n,d);
    for(int i=1;i<=n;i++) 
    {
        int x;cin>>x;
        d[i]=d[i-1]+x;
    }
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            d[i]=min(d[i],d[j]+d[i-j]+d[0]);
    printf("%d\n",d[n]);
    return 0;
}