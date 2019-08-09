#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+50,inf=0x3f3f3f3f;
int n,m,a[N],out[N];
int dist(int x,int y)
{
    return y>=x?y-x:y-x+n;
}
int main()
{
    for(int i=0;i<5005;i++) a[i]=inf;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y>=x) a[x]=min(a[x],y-x);
        else a[x]=min(a[x],y-x+n);
        out[x]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        for(int j=1;j<=n;j++)
        {
            if(out[j]>0)
            ans=max(ans,dist(i,j)+n*(out[j]-1)+a[j]);
        }
        cout<<ans<<" ";
    }
    return 0;

}

