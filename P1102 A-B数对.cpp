#include<bits/stdc++.h>
using namespace std;
int n,c,num[200005];
long long ans;
map<int,int>a;
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        a[num[i]]++;
    }
    for(int i=1;i<=n;i++)
        ans+=a[num[i]+c];
    printf("%lld\n",ans);
    return 0;
}