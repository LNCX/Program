#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,d,ans=0,sum=0;
    scanf("%d%d%d",&n,&b,&d);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        if(x>b)continue;
        sum+=x;
        if(sum>d)
        {
            ans++;
            sum=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}