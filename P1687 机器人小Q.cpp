#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,inf=0x3f3f3f3f;
int a[N],n,k,f[N][N];
bool check(int x)
{
    memset(f,inf,sizeof(f));
    for(int i=1;i<=n;i++)
        if(a[i]>119)continue;
        else f[a[i]][1]=1;
    for(int i=1;i<=n;i++)
        for(int v=119;v>=a[i];v--)
            for(int j=1;j<=x;j++)
                f[v][j]=min(f[v-a[i]][j]+1,min(f[v-a[i]][j]+1,f[v][j]));
    return f[119][x]>=k;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else r=mid+1;
    }        
    cout<<ans<<endl;
    return 0;
}