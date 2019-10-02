#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
vector<int>pos[N];
int cal(int x,int y,int k)
{
    int a[2]={x,y},b[2];
    for(int i=0;i<2;i++)
    {
        if(a[i]<k) b[i]=a[i]+1;
        else if(a[i]==k) b[i]=1;
        else b[i]=a[i];
    }
    return abs(b[0]-b[1]);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%lld",&a[i]),pos[a[i]].push_back(i);
    for(int i=1;i<m;i++)
        ans+=abs(a[i]-a[i+1]);
    printf("%lld ",ans);
    for(int i=2;i<=n;i++)
    {
        int j=i-1;
        for(int l=j;l<=i;l++)
            for(auto k:pos[l])
            {
                if(k!=1) ans-=cal(a[k],a[k-1],j),ans+=cal(a[k],a[k-1],i);
                if(k!=m) ans-=cal(a[k],a[k+1],j),ans+=cal(a[k],a[k+1],i);
            }
        printf("%lld ",ans);
    }
    puts("");
    return 0;
}