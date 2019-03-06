#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,b,k,a[maxn],ans=0x3f3f3f3f,s[maxn];
int main()
{
    scanf("%d%d%d",&n,&k,&b);
    for(int i=1;i<=b;i++) 
    {
        int x;
        scanf("%d",&x);
        a[x]=1;
    }
    for(int i=1;i<=n;i++) 
        s[i]=s[i-1]+a[i];
    for(int i=k;i<=n;i++) 
        ans=min(ans,s[i]-s[i-k]);
    printf("%d\n",ans);
}