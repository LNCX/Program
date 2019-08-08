#include<bits/stdc++.h>
using namespace std;
const int N=200010;
typedef long long LL;
LL a[N],b[N],s,sum,Y;
int n,m,maxx=-1,minx=2147483647;
int w[N],v[N],L[N],R[N];
bool check(int X)
{   
    Y=0,sum=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        if(w[i]>=X) a[i]=a[i-1]+1,b[i]=b[i-1]+v[i];
        else a[i]=a[i-1],b[i]=b[i-1];
    }
    for(int i=1;i<=m;i++)
        Y+=(a[R[i]]-a[L[i]-1])*(b[R[i]]-b[L[i]-1]);
    sum=llabs(Y-s);
    if(Y>s) return true;
    else return false;

}
int main()
{
    scanf("%d%d%lld",&n,&m,&s); 
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
        maxx=max(maxx,w[i]);
        minx=min(minx,w[i]);    
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d",&L[i],&R[i]);
    int l=minx-1,r=maxx+2;
    LL ans=0x7FFFFFFFFFFFFFFF;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))  l=mid+1;
        else r=mid-1;
        if(sum<ans) ans=sum;
    }
    cout<<ans<<endl;
    return 0;
} 