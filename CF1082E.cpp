#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cnt,ans;
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==c) cnt++;
        else
        {
            if(a[x]<cnt) a[x]=cnt;
            a[x]++;
            ans=max(ans,a[x]-cnt);
        }
    }
    cout<<ans+cnt<<endl;
}