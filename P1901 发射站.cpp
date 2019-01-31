#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long s[maxn],h[maxn],v[maxn],sum[maxn],ans,top;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&h[i],&v[i]);
        while(top&&h[s[top]]<h[i])
            sum[i]+=v[s[top--]];
        sum[s[top]]+=v[i];
        s[++top]=i;
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,sum[i]);
    printf("%lld\n",ans);
    return 0;
}