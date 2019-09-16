#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,f[N],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,maxx=0;
        scanf("%d",&x);
        for(int i=0;i<=31;i++)
            if((1<<i)&x)
                maxx=max(maxx,f[i]+1);
        for(int i=0;i<=31;i++)
            if((1<<i)&x)
                f[i]=maxx;
    }
    for(int i=0;i<=31;i++)
        ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}