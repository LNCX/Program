#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,a[N],b[N],cnt[N],ans;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++,b[a[i]]=i;
    }   
    int l=1,r=0,mx=0; 
    for(int i=1;i<=n;i++)
    {
        r=max(r,b[a[i]]);
        mx=max(mx,cnt[a[i]]);
        if(i==r)
        {
            ans+=(r-l+1)-mx;
            l=r+1,r=mx=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}