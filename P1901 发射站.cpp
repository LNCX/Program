#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long s[N],h[N],v[N],sum[N],ans,top;
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