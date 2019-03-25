#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w,ans,cnt[9];
void dfs(LL x,LL len)
{
    if(x==9)
    {
        if(ans<len)
            ans=len;
        return;
    }
    LL v=min((w-len)/x,cnt[x]);
    for(int i=9;i>=1;i--)
        dfs(x+1,len+max( (LL)0,(v--)*x) );
}
int main() 
{
    scanf("%lld",&w);
    for(int i=1;i<=8;i++) 
        scanf("%lld",&cnt[i]);
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}